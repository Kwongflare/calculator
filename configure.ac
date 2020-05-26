# Initialization
AC_PREREQ([2.69])
AC_INIT([calculator], [1.0], [https://github.com/openbmc/phosphor-user-manager/issues])
AC_LANG([C++])
AC_CONFIG_HEADERS([config.h])

AM_SILENT_RULES([yes])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries.
PKG_CHECK_MODULES([SDBUSPLUS], [sdbusplus])
PKG_CHECK_MODULES([PHOSPHOR_DBUS_INTERFACES], [phosphor-dbus-interfaces])

AC_ARG_VAR(CALCULATOR_BUSNAME, [The Dbus busname to own])
AS_IF([test "x$CALCULATOR_BUSNAME" == "x"], [CALCULATOR_BUSNAME="ryan.chow.Calculator"])
AC_DEFINE_UNQUOTED([CALCULATOR_BUSNAME], ["$CALCULATOR_BUSNAME"], [The DBus busname to own])

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_17([noext])
AX_APPEND_COMPILE_FLAGS([-Wall -Werror], [CXXFLAGS])

# For libtools
LT_INIT

# Create configured output
AC_OUTPUT