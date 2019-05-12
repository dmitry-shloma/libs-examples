TEMPLATE = lib
VERSION = 0.0.1

CONFIG -= qt

SOURCES += matrices.cpp

HEADERS += matrices.h

# BuildEssentials dir
BUILD_ESSENTIALS_DIR = $$PWD/../BuildEssentials

include($${BUILD_ESSENTIALS_DIR}/deployment.pri)
qtcAddDeployment()

include($${BUILD_ESSENTIALS_DIR}/environment.pri)
include($${BUILD_ESSENTIALS_DIR}/helper.pri)
#
