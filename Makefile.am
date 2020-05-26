bin_PROGRAMS = calculator

calculator_LDFLAGS = $(SDBUSPLUS_LIBS) \
                     $(BOOST_CPPFLAGS) \
                     -lstdc++fs

calculator_CXXFLAGS = $(SYSTEMD_CFLAGS) \
                      $(PHOSPHOR_DBUS_INTERFACES_LIBS) \
                      $(BOOST_CPPFLAGS) \
                      -DBOOST_ALL_NO_LIB \
                      -DBOOST_SYSTEM_NO_DEPRECATED \
                      -DBOOST_ERROR_CODE_HEADER_ONLY

calculator_server_generated_files = \
	ryan/chow/Calculator/server.hpp \
	ryan/chow/Calculator/server.cpp \
	ryan/chow/Calculator/error.hpp \
	ryan/chow/Calculator/error.cpp \
	ryan/chow/Calculator/client.hpp

calculator_SOURCES = \
	calculator-server.cpp $(calculator_server_generated_files)
calculator_LDADD = $(SYSTEMD_LIBS) libsdbusplus.la

BUILT_SOURCES = \
	$(calculator_server_generated_files) 
CLEANFILES = \
	$(calculator_server_generated_files) 

#ryan/chow/Calculator/server.hpp:
#	@mkdir -p $(@D)
#	sdbus++ interface server-header ryan.chow.Calculator > ryan/chow/Calculator/server.hpp

#ryan/chow/Calculator/server.cpp:
#	@mkdir -p $(@D)
#	sdbus++ interface server-cpp ryan.chow.Calculator > ryan/chow/Calculator/server.cpp

#ryan/chow/Calculator/error.hpp:
#	@mkdir -p $(@D)
#	sdbus++ error exception-header ryan.chow.Calculator > ryan/chow/Calculator/error.hpp

#ryan/chow/Calculator/error.cpp:
#	@mkdir -p $(@D)
#	sdbus++ error exception-cpp ryan.chow.Calculator > ryan/chow/Calculator/error.cpp

#ryan/chow/Calculator/client.hpp:
#	@mkdir -p $(@D)
#	sdbus++ interface client-header ryan.chow.Calculator > ryan/chow/Calculator/client.hpp
