#include <ryan/chow/Calculator/error.hpp>

namespace sdbusplus
{
namespace ryan
{
namespace chow
{
namespace Calculator
{
namespace Error
{
const char* DivisionByZero::name() const noexcept
{
    return errName;
}
const char* DivisionByZero::description() const noexcept
{
    return errDesc;
}
const char* DivisionByZero::what() const noexcept
{
    return errWhat;
}
const char* PermissionDenied::name() const noexcept
{
    return errName;
}
const char* PermissionDenied::description() const noexcept
{
    return errDesc;
}
const char* PermissionDenied::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Calculator
} // namespace chow
} // namespace ryan
} // namespace sdbusplus

