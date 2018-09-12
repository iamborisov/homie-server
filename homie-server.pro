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
            common/Service.h

    SOURCES += \
            main.cpp \
            common/Service.cpp

# Services --------------------------------------------------------------------

    HEADERS += \
            Container/Container.h \
            Application/Application.h \
            Application/ApplicationConsole.h \
            Arguments/Arguments.h \
            Arguments/ArgumentsConsole.h \
            Configuration/Configuration.h \
            Configuration/ConfigurationOption.h \
            Configuration/ConfigurationGroup.h \
            Configuration/ConfigurationService.h \
            Configuration/Source/ConfigurationSource.h \
            Configuration/Source/ConfigurationSourceFile.h \
            Configuration/Source/ConfigurationSourceArguments.h \
            Configuration/Resolver/ConfigurationResolver.h \
            Configuration/Resolver/ConfigurationResolverPriority.h

    SOURCES += \
            Container/Container.cpp \
            Application/Application.cpp \
            Application/ApplicationConsole.cpp \
            Arguments/Arguments.cpp \
            Arguments/ArgumentsConsole.cpp \
            Configuration/Configuration.cpp \
            Configuration/ConfigurationOption.cpp \
            Configuration/ConfigurationGroup.cpp \
            Configuration/ConfigurationService.cpp \
            Configuration/Source/ConfigurationSource.cpp \
            Configuration/Source/ConfigurationSourceFile.cpp \
            Configuration/Source/ConfigurationSourceArguments.cpp \
            Configuration/Resolver/ConfigurationResolver.cpp \
            Configuration/Resolver/ConfigurationResolverPriority.cpp

# Environment Dependencies ----------------------------------------------------

    # Debug
    CONFIG(debug, debug|release) {
        HEADERS += \
                Container/Environment/ContainerDebug.h \
                Configuration/Environment/ConfigurationDebug.h \
                Test/TestService.h \
                Test/TestServiceImpl.h

        SOURCES += \
                Container/Environment/ContainerDebug.cpp \
                Configuration/Environment/ConfigurationDebug.cpp \
                Test/TestService.cpp \
                Test/TestServiceImpl.cpp
    }

    # Release
    CONFIG(release, debug|release) {
        HEADERS += \
                Container/Environment/ContainerRelease.h \
                Configuration/Environment/ConfigurationRelease.h

        SOURCES += \
                Container/Environment/ContainerRelease.cpp \
                Configuration/Environment/ConfigurationRelease.cpp
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
