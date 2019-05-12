include(../../environment.pri)

TEMPLATE = lib

unix: VERSION = 0.1.0

CONFIG += shared

HEADERS += \
    mockdevice.h

SOURCES += \
    mockdevice.c
