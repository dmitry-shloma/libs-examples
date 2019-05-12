include(../environment.pri)
include(../deploy.pri)

PLUGINS_DIR = $${PWD}/../plugins
PROJECT_DIR = $${PWD}/../..

INCLUDEPATH += $${PLUGINS_DIR}
DEPENDPATH += $${PLUGINS_DIR}

TEMPLATE = app

SOURCES += \
    main.c

#LIBS += -L$${PROJECT_DIR}/build/src/plugins/realdevice -lrealdevice
LIBS += -ldl

copyDirs($${PROJECT_DIR}/build/src/plugins/mockdevice/$${MODE}/bin, $${DESTDIR}/../)
copyDirs($${PROJECT_DIR}/build/src/plugins/realdevice/$${MODE}/bin, $${DESTDIR}/../)
