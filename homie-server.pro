#==============================================================================
#  APPLICATION INFORMATION
#==============================================================================

    NAME = Homie-Server
    VERSION = 1.0.0

#==============================================================================
#  SOURCES
#==============================================================================

# Common ----------------------------------------------------------------------

    HEADERS += \
            common/fruit.h \
            common/QStringListConverter.h \
            common/Service.h

    SOURCES += \
            main.cpp \
            common/QStringListConverter.cpp \
            common/Service.cpp

# Services --------------------------------------------------------------------

    HEADERS += \
            Application/Application.h \
            Application/ApplicationConsole.h \
            Arguments/Arguments.h \
            Arguments/ArgumentsConsole.h \
            Configuration/Configuration.h \
            Configuration/ConfigurationFile.h

    SOURCES += \
            Application/Application.cpp \
            Application/ApplicationConsole.cpp \
            Arguments/Arguments.cpp \
            Arguments/ArgumentsConsole.cpp \
            Configuration/Configuration.cpp \
            Configuration/ConfigurationFile.cpp

# Environment Containers ------------------------------------------------------

    HEADERS += Container/Container.h
    SOURCES += Container/Container.cpp

    CONFIG(debug, debug|release) {
        HEADERS += Container/ContainerDebug.h
        SOURCES += Container/ContainerDebug.cpp
    }

    CONFIG(release, debug|release) {
        HEADERS += Container/ContainerRelease.h
        SOURCES += Container/ContainerRelease.cpp
    }

#==============================================================================
#  QT CONFIGURATION
#==============================================================================

    QT -= gui

    CONFIG += c++11 console
    CONFIG -= app_bundle

    # Display deprication warnings
    DEFINES += QT_DEPRECATED_WARNINGS

    # Disable all the APIs deprecated before Qt 6.0.0
    #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

#==============================================================================
#  EXTERNAL DEPENDENCIES
#==============================================================================

    # Google Fruit DI-framework
    # https://github.com/google/fruit
    unix|win32: LIBS += -ldl -lfruit

#==============================================================================
#  ADDITIONAL DEFINITIONS
#==============================================================================

# Debug -----------------------------------------------------------------------

    CONFIG(debug, debug|release) {
        VERSION = $${VERSION}-dev
        DEFINES += DEBUG
    }

# Strings ---------------------------------------------------------------------

    DEFINES += APP_NAME=\\\"$${NAME}\\\"
    DEFINES += APP_VERSION=\\\"$${VERSION}\\\"
