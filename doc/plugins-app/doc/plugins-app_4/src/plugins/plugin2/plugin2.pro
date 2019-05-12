PROJECT_DIR = $${PWD}/../../..
PLUGINS_DIR = $${PROJECT_DIR}/src/plugins

include($${PROJECT_DIR}/src/environment.pri)
include($${PROJECT_DIR}/src/deploy.pri)

INCLUDEPATH += $${PLUGINS_DIR}
DEPENDPATH += $${PLUGINS_DIR}

TEMPLATE = lib

unix: VERSION = 0.0.1

CONFIG += shared

HEADERS += \
    $${PLUGINS_DIR}/plugins.h

SOURCES += \
    plugin2.c
