#==============================================================================
#  APPLICATION INFORMATION
#==============================================================================

NAME = Homie-Server
VERSION = 1.0.0
DESCRIPTION = put_application_description_here

#==============================================================================
#  SOURCES
#==============================================================================

SOURCES = \
	main.cpp \
	Application.cpp \
	Configuration.cpp \
	ConfigurationArguments.cpp \
	ConfigurationFile.cpp \
	Container.cpp \
	ContainerDebug.cpp \
	ContainerRelease.cpp \
	ContainerTest.cpp

HEADERS = \
	Application.h \
	Configuration.h \
	ConfigurationArguments.h \
	ConfigurationFile.h \
	Container.h \
	ContainerDebug.h \
	ContainerRelease.h \
	ContainerTest.h

#==============================================================================
#  QT CONFIGURATION
#==============================================================================

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
#CONFIG += object_parallel_to_source

DEFINES += QT_DEPRECATED_WARNINGS # Display deprication warnings
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000 # Disable all the APIs deprecated before Qt 6.0.0

#==============================================================================
#  EXTERNAL DEPENDENCIES
#==============================================================================

# Google Fruit DI-framework
# https://github.com/google/fruit
unix|win32: LIBS += -ldl -lfruit

#==============================================================================
#  ADDITIONAL DEFINITIONS
#==============================================================================

CONFIG(debug, debug|release) {
    VERSION = $${VERSION}-dev
}

DEFINES += APP_NAME=\\\"$${NAME}\\\"
DEFINES += APP_VERSION=\\\"$${VERSION}\\\"
DEFINES += APP_DESCRIPTION=\\\"$${DESCRIPTION}\\\"
