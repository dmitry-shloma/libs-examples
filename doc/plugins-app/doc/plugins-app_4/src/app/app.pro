PROJECT_DIR = $${PWD}/../..
PLUGINS_DIR = $${PROJECT_DIR}/src/plugins

include($${PROJECT_DIR}/src/environment.pri)
include($${PROJECT_DIR}/src/deploy.pri)

INCLUDEPATH += $${PLUGINS_DIR}
DEPENDPATH += $${PLUGINS_DIR}

TEMPLATE = app

SOURCES += \
    main.c

LIBS += -ldl

copyDirs($${PROJECT_DIR}/build/src/plugins/mockdevice/$${MODE}/bin, $${DESTDIR}/../)
copyDirs($${PROJECT_DIR}/build/src/plugins/realdevice/$${MODE}/bin, $${DESTDIR}/../)
