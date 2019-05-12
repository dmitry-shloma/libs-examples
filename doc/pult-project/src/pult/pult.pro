include(../deploy.pri)
include(../environment.pri)

DEVICES_DIR = $${PWD}/../devices
#PROJECT_DIR = $${PWD}/../..

INCLUDEPATH += $${DEVICES_DIR}

TEMPLATE = app

SOURCES += \
    main.c

#LIBS += -L$${PROJECT_DIR}/build/src/pult/debug/bin -lrealtransmitter
