#==============================================================================
#  APPLICATION INFORMATION
#==============================================================================

NAME = Homie-Server
VERSION = 1.0.0

#==============================================================================
#  SOURCES
#==============================================================================

SOURCES = \
	main.cpp \
        Application/Application.cpp \
        Application/ApplicationConsole.cpp \
        Arguments/Arguments.cpp \
        Arguments/ArgumentsConsole.cpp \
        Configuration/Configuration.cpp \
        Configuration/ConfigurationFile.cpp \
        Container/Container.cpp \
        Container/ContainerDebug.cpp \
        Container/ContainerRelease.cpp \
        Container/ContainerTest.cpp

HEADERS = \
        Application/Application.h \
        Application/ApplicationConsole.h \
        Arguments/Arguments.h \
        Arguments/ArgumentsConsole.h \
        Configuration/Configuration.h \
        Configuration/ConfigurationFile.h \
        Container/Container.h \
        Container/ContainerDebug.h \
        Container/ContainerRelease.h \
        Container/ContainerTest.h \
        fruit.h

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
