TEMPLATE = app
VERSION = 0.0.1

CONFIG -= qt

HEADERS += ../Src/RpnCalc/rpncalc.h

SOURCES += main.cpp

LIBS += -ldl

# BuildEssentials dir
BUILD_ESSENTIALS_DIR = $$PWD/../BuildEssentials

include($${BUILD_ESSENTIALS_DIR}/deployment.pri)
qtcAddDeployment()

include($${BUILD_ESSENTIALS_DIR}/environment.pri)
include($${BUILD_ESSENTIALS_DIR}/helper.pri)
#
