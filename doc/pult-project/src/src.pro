TEMPLATE = subdirs

SUBDIRS += \
    devices \
    pult

pult.depends = devices
