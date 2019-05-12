include(environment.pri)

QT -= gui

TARGET = SampleSharedLib
TARGET = $$sampleSharedLibTarget($${TARGET})

TEMPLATE = lib
CONFIG += shared

DEFINES += SAMPLESHAREDLIB_LIBRARY

SOURCES += samplesharedlib.cpp

HEADERS += \
    samplesharedlib.h \
    samplesharedlib_global.h

## NovaTel
#NOVATEL_PATH = $$PWD/../NovaTel
#NOVATEL_INC_PATH = $${NOVATEL_PATH}/include
#NOVATEL_LIB_PATH = $${NOVATEL_PATH}/lib

#INCLUDEPATH += $${NOVATEL_INC_PATH}
#DEPENDPATH += $${NOVATEL_INC_PATH}

#NOVATEL_LIB = NovaTel$${DEBUG_SFX}
#LIBS += -L$${NOVATEL_LIB_PATH} -l$${NOVATEL_LIB}

#PRE_TARGETDEPS += $${NOVATEL_LIB_PATH}/$${NOVATEL_LIB}.lib
##
