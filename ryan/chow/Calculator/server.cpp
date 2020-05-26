#include <algorithm>
#include <map>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <sdbusplus/exception.hpp>
#include <string>
#include <tuple>
#include <variant>

#include <ryan/chow/Calculator/server.hpp>


#include <ryan/chow/Calculator/error.hpp>




#include <ryan/chow/Calculator/error.hpp>


namespace sdbusplus
{
namespace ryan
{
namespace chow
{
namespace server
{

Calculator::Calculator(bus::bus& bus, const char* path)
        : _ryan_chow_Calculator_interface(
                bus, path, interface, _vtable, this), _intf(bus.getInterface())
{
}

Calculator::Calculator(bus::bus& bus, const char* path,
                           const std::map<std::string, PropertiesVariant>& vals,
                           bool skipSignal)
        : Calculator(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}


int Calculator::_callback_Multiply(
        sd_bus_message* msg, void* context, sd_bus_error* error)
{
    try
    {
        auto m = message::message(msg);
#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        int64_t x{};
    int64_t y{};

        m.read(x, y);

        auto o = static_cast<Calculator*>(context);
        auto r =         o->multiply(x, y);

        auto reply = m.new_method_return();
        reply.append(std::move(r));

        reply.method_return();
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Calculator
{
static const auto _param_Multiply =
        utility::tuple_to_array(message::types::type_id<
                int64_t, int64_t>());
static const auto _return_Multiply =
        utility::tuple_to_array(message::types::type_id<
                int64_t>());
}
}

int Calculator::_callback_Divide(
        sd_bus_message* msg, void* context, sd_bus_error* error)
{
    try
    {
        auto m = message::message(msg);
#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        int64_t x{};
    int64_t y{};

        m.read(x, y);

        auto o = static_cast<Calculator*>(context);
        auto r =         o->divide(x, y);

        auto reply = m.new_method_return();
        reply.append(std::move(r));

        reply.method_return();
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch(sdbusplus::ryan::chow::Calculator::Error::DivisionByZero& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Calculator
{
static const auto _param_Divide =
        utility::tuple_to_array(message::types::type_id<
                int64_t, int64_t>());
static const auto _return_Divide =
        utility::tuple_to_array(message::types::type_id<
                int64_t>());
}
}

int Calculator::_callback_Clear(
        sd_bus_message* msg, void* context, sd_bus_error* error)
{
    try
    {
        auto m = message::message(msg);
#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif


        auto o = static_cast<Calculator*>(context);
        o->clear();

        auto reply = m.new_method_return();
        // No data to append on reply.

        reply.method_return();
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Calculator
{
static const auto _param_Clear =
        utility::tuple_to_array(std::make_tuple('\0'));
static const auto _return_Clear =
        utility::tuple_to_array(std::make_tuple('\0'));
}
}


void Calculator::cleared(
            int64_t unnamed)
{
    auto& i = _ryan_chow_Calculator_interface;
    auto m = i.new_signal("Cleared");

    m.append(unnamed);
    m.signal_send();
}

namespace details
{
namespace Calculator
{
static const auto _signal_Cleared =
        utility::tuple_to_array(message::types::type_id<
                int64_t>());
}
}


auto Calculator::lastResult() const ->
        int64_t
{
    return _lastResult;
}

int Calculator::_callback_get_LastResult(
        sd_bus* bus, const char* path, const char* interface,
        const char* property, sd_bus_message* reply, void* context,
        sd_bus_error* error)
{
    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Calculator*>(context);

    try
    {
        auto m = message::message(reply, o->_intf);

#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        m.append(o->lastResult());
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Calculator::lastResult(int64_t value,
                                         bool skipSignal) ->
        int64_t
{
    if (_lastResult != value)
    {
        _lastResult = value;
        if (!skipSignal)
        {
            _ryan_chow_Calculator_interface.property_changed("LastResult");
        }
    }

    return _lastResult;
}

auto Calculator::lastResult(int64_t val) ->
        int64_t
{
    return lastResult(val, false);
}
int Calculator::_callback_set_LastResult(
        sd_bus* bus, const char* path, const char* interface,
        const char* property, sd_bus_message* value, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<Calculator*>(context);

    try
    {
        auto m = message::message(value, o->_intf);

#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        int64_t v{};
        m.read(v);
        o->lastResult(v);
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Calculator
{
static const auto _property_LastResult =
    utility::tuple_to_array(message::types::type_id<
            int64_t>());
}
}

auto Calculator::status() const ->
        State
{
    return _status;
}

int Calculator::_callback_get_Status(
        sd_bus* bus, const char* path, const char* interface,
        const char* property, sd_bus_message* reply, void* context,
        sd_bus_error* error)
{
    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Calculator*>(context);

    try
    {
        auto m = message::message(reply, o->_intf);

#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        m.append(o->status());
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Calculator::status(State value,
                                         bool skipSignal) ->
        State
{
    if (_status != value)
    {
        _status = value;
        if (!skipSignal)
        {
            _ryan_chow_Calculator_interface.property_changed("Status");
        }
    }

    return _status;
}

auto Calculator::status(State val) ->
        State
{
    return status(val, false);
}
int Calculator::_callback_set_Status(
        sd_bus* bus, const char* path, const char* interface,
        const char* property, sd_bus_message* value, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<Calculator*>(context);

    try
    {
        auto m = message::message(value, o->_intf);

#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        State v{};
        m.read(v);
        o->status(v);
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Calculator
{
static const auto _property_Status =
    utility::tuple_to_array(message::types::type_id<
            ryan::chow::server::Calculator::State>());
}
}

auto Calculator::owner() const ->
        std::string
{
    return _owner;
}

int Calculator::_callback_get_Owner(
        sd_bus* bus, const char* path, const char* interface,
        const char* property, sd_bus_message* reply, void* context,
        sd_bus_error* error)
{
    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Calculator*>(context);

    try
    {
        auto m = message::message(reply, o->_intf);

#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        m.append(o->owner());
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }
    catch(sdbusplus::ryan::chow::Calculator::Error::PermissionDenied& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Calculator::owner(std::string value,
                                         bool skipSignal) ->
        std::string
{
    if (_owner != value)
    {
        _owner = value;
        if (!skipSignal)
        {
            _ryan_chow_Calculator_interface.property_changed("Owner");
        }
    }

    return _owner;
}

auto Calculator::owner(std::string val) ->
        std::string
{
    return owner(val, false);
}
int Calculator::_callback_set_Owner(
        sd_bus* bus, const char* path, const char* interface,
        const char* property, sd_bus_message* value, void* context,
        sd_bus_error* error)
{
    auto o = static_cast<Calculator*>(context);

    try
    {
        auto m = message::message(value, o->_intf);

#if 0
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id
                (std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        std::string v{};
        m.read(v);
        o->owner(v);
    }
    catch(sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }
    catch(sdbusplus::ryan::chow::Calculator::Error::PermissionDenied& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Calculator
{
static const auto _property_Owner =
    utility::tuple_to_array(message::types::type_id<
            std::string>());
}
}

void Calculator::setPropertyByName(const std::string& _name,
                                     const PropertiesVariant& val,
                                     bool skipSignal)
{
    if (_name == "LastResult")
    {
        auto& v = std::get<int64_t>(val);
        lastResult(v, skipSignal);
        return;
    }
    if (_name == "Status")
    {
        auto& v = std::get<State>(val);
        status(v, skipSignal);
        return;
    }
    if (_name == "Owner")
    {
        auto& v = std::get<std::string>(val);
        owner(v, skipSignal);
        return;
    }
}

auto Calculator::getPropertyByName(const std::string& _name) ->
        PropertiesVariant
{
    if (_name == "LastResult")
    {
        return lastResult();
    }
    if (_name == "Status")
    {
        return status();
    }
    if (_name == "Owner")
    {
        return owner();
    }

    return PropertiesVariant();
}


namespace
{
/** String to enum mapping for Calculator::State */
static const std::tuple<const char*, Calculator::State> mappingCalculatorState[] =
        {
            std::make_tuple( "ryan.chow.Calculator.State.Success",                 Calculator::State::Success ),
            std::make_tuple( "ryan.chow.Calculator.State.Error",                 Calculator::State::Error ),
        };

} // anonymous namespace

auto Calculator::convertStateFromString(const std::string& s) ->
        State
{
    auto i = std::find_if(
            std::begin(mappingCalculatorState),
            std::end(mappingCalculatorState),
            [&s](auto& e){ return 0 == strcmp(s.c_str(), std::get<0>(e)); } );
    if (std::end(mappingCalculatorState) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string Calculator::convertStateToString(Calculator::State v)
{
    auto i = std::find_if(
            std::begin(mappingCalculatorState),
            std::end(mappingCalculatorState),
            [v](auto& e){ return v == std::get<1>(e); });
    if (i == std::end(mappingCalculatorState))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

const vtable::vtable_t Calculator::_vtable[] = {
    vtable::start(),

    vtable::method("Multiply",
                   details::Calculator::_param_Multiply
                        .data(),
                   details::Calculator::_return_Multiply
                        .data(),
                   _callback_Multiply),

    vtable::method("Divide",
                   details::Calculator::_param_Divide
                        .data(),
                   details::Calculator::_return_Divide
                        .data(),
                   _callback_Divide),

    vtable::method("Clear",
                   details::Calculator::_param_Clear
                        .data(),
                   details::Calculator::_return_Clear
                        .data(),
                   _callback_Clear),

    vtable::signal("Cleared",
                   details::Calculator::_signal_Cleared
                        .data()),
    vtable::property("LastResult",
                     details::Calculator::_property_LastResult
                        .data(),
                     _callback_get_LastResult,
                     _callback_set_LastResult,
                     vtable::property_::emits_change),
    vtable::property("Status",
                     details::Calculator::_property_Status
                        .data(),
                     _callback_get_Status,
                     vtable::property_::const_),
    vtable::property("Owner",
                     details::Calculator::_property_Owner
                        .data(),
                     _callback_get_Owner,
                     _callback_set_Owner,
                     vtable::property_::emits_change),
    vtable::end()
};

} // namespace server
} // namespace chow
} // namespace ryan
} // namespace sdbusplus

