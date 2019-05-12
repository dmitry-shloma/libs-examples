PROJECT_DIR = $${PWD}/../..
LIBS_DIR = $${PROJECT_DIR}/src/plugins

include($${PROJECT_DIR}/src/environment.pri)
include($${PROJECT_DIR}/src/deploy.pri)

INCLUDEPATH += $${LIBS_DIR}
DEPENDPATH += $${LIBS_DIR}

TEMPLATE = app

SOURCES += \
    main.c

LIBS += -ldl

copyDirs($${PROJECT_DIR}/build/src/plugins/mockdevice/$${MODE}/bin, $${DESTDIR}/../)
copyDirs($${PROJECT_DIR}/build/src/plugins/realdevice/$${MODE}/bin, $${DESTDIR}/../)
