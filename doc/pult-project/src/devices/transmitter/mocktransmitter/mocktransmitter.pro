include(../../../deploy.pri)
include(../../../environment.pri)

TRANSMITTER_DIR = $${PWD}/..

INCLUDEPATH += $${TRANSMITTER_DIR}
DEPENDPATH += $${TRANSMITTER_DIR}

TEMPLATE = lib

unix: VERSION = 0.0.1

CONFIG += shared

HEADERS += \
    $${TRANSMITTER_DIR}/transmitter.h

SOURCES += \
    mocktransmitter.c
