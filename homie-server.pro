#==============================================================================
#  APPLICATION INFORMATION
#==============================================================================
NAME = Homie-Server
VERSION = 1.0.0-dev
DESCRIPTION = put_application_description_here

#==============================================================================
#  SOURCE CODE
#==============================================================================
SOURCES += \
        main.cpp \
    homie.cpp \
    container/container.cpp

HEADERS += \
    homie.h \
    container/container.h

#==============================================================================
#  EXTERNAL DEPENDENCIES
#==============================================================================

# Google Fruit DI-framework
# https://github.com/google/fruit
unix|win32: LIBS += -lfruit

#==============================================================================
#  QT CONFIGURATION
#==============================================================================
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS # Display deprication warnings
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000 # Disable all the APIs deprecated before Qt 6.0.0

#==============================================================================
#  DEPLOYMENT
#==============================================================================
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#==============================================================================
#  ADDITIONAL DEFINITIONS
#==============================================================================
DEFINES += APP_NAME=\\\"$${NAME}\\\"
DEFINES += APP_VERSION=\\\"$${VERSION}\\\"
DEFINES += APP_DESCRIPTION=\\\"$${DESCRIPTION}\\\"
