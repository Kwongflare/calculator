bin_PROGRAMS = calculator

calculator_SOURCES = \
            calculator-server.cpp

calculator_LDFLAGS = $(SDBUSPLUS_LIBS) \
                     $(BOOST_CPPFLAGS)

calculator_CXXFLAGS = $(SYSTEMD_CFLAGS) \
                      $(PHOSPHOR_DBUS_INTERFACES_LIBS) \
                      $(BOOST_CPPFLAGS) \
                      -DBOOST_ALL_NO_LIB \
                      -DBOOST_SYSTEM_NO_DEPRECATED \
                      -DBOOST_ERROR_CODE_HEADER_ONLY