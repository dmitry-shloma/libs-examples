PLUGINS_DIR = $${PWD}/../plugins
PROJECT_DIR = $${PWD}/../..

include($${PROJECT_DIR}/environment.pri)

INCLUDEPATH += $${PLUGINS_DIR}
DEPENDPATH += $${PLUGINS_DIR}

TEMPLATE = app

SOURCES += \
    main.c

LIBS += -L$${PROJECT_DIR}/build/src/plugins/plugin1/debug -lplugin1
LIBS += -L$${PROJECT_DIR}/build/src/plugins/plugin2/debug -lplugin2
