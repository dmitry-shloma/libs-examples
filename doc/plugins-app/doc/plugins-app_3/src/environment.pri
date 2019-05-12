# flags
#QMAKE_CXXFLAGS +=-std=c++0x

MODE=

# dirs
CONFIG(debug, debug|release) {
    BUILD_DIR = $${OUT_PWD}/debug
    MODE=debug
}

CONFIG(release, debug|release) {
    BUILD_DIR = $${OUT_PWD}/release
    MODE=release
}

DESTDIR = $${BUILD_DIR}/bin
MOC_DIR = $${BUILD_DIR}/moc
OBJECTS_DIR = $${BUILD_DIR}/obj
RCC_DIR = $${BUILD_DIR}/rcc
UI_DIR = $${BUILD_DIR}/ui
