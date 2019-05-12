PROJECT_DIR = $${PWD}/../../..

include($${PROJECT_DIR}/src/environment.pri)
include($${PROJECT_DIR}/src/deploy.pri)

TEMPLATE = lib

unix: VERSION = 0.0.1

CONFIG += static

HEADERS += \
    static.h

SOURCES += \
    static.c
