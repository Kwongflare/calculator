#include <iostream>
#include <ryan/chow/Calculator/client.hpp>
#include <ryan/chow/Calculator/error.hpp>
#include <ryan/chow/Calculator/server.hpp>
#include <sdbusplus/server.hpp>
#include <string_view>

using Calculator_inherit =
    sdbusplus::server::object_t<sdbusplus::ryan::chow::server::Calculator>;

/** Example implementation of ryan.chow.Calculator */
struct Calculator : Calculator_inherit
{
    /** Constructor */
    Calculator(sdbusplus::bus::bus& bus, const char* path) :
        Calculator_inherit(bus, path)
    {
    }

    /** Multiply (x*y), update lastResult */
    int64_t multiply(int64_t x, int64_t y) override
    {
        return lastResult(x * y);
    }

    /** Divide (x/y), update lastResult
     *
     *  Throws DivisionByZero on error.
     */
    int64_t divide(int64_t x, int64_t y) override
    {
        using sdbusplus::ryan::chow::Calculator::Error::DivisionByZero;
        if (y == 0)
        {
            status(State::Error);
            throw DivisionByZero();
        }

        return lastResult(x / y);
    }

    /** Clear lastResult, broadcast 'Cleared' signal */
    void clear() override
    {
        auto v = lastResult();
        lastResult(0);
        cleared(v);
        return;
    }
};

int main()
{
    // Define a dbus path location to place the object.
    constexpr auto path = "/ryan/chow/Calculator";

    static_assert(
        std::string_view(
            sdbusplus::ryan::chow::client::Calculator::interface) ==
        std::string_view(Calculator::interface));

    // Create a new bus and affix an object manager for the subtree path we
    // intend to place objects at..
    auto b = sdbusplus::bus::new_default();
    sdbusplus::server::manager_t m{b, path};

    // Reserve the dbus service name : ryan.chow.Calculator
    b.request_name(CALCULATOR_BUSNAME);

    // Create a calculator object at /ryan/chow/Calculator
    Calculator c1{b, path};

    // Handle dbus processing forever.
    while (1)
    {
        b.process_discard(); // discard any unhandled messages
        b.wait();
    }

    return 0;
}
