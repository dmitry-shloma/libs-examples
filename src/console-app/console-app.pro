TEMPLATE = app

CONFIG += console
CONFIG -= qt

SOURCES = \
    main.c

LIBS = -L./../static-lib -lstatic-lib
LIBS += -L./../shared-lib -lshared-lib
