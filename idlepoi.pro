
VERSION = 1.0.4

QT       += core gui webkit network widgets webkitwidgets

TARGET = idlepoi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gikopoiwebpage.cpp

HEADERS  += mainwindow.h \
    gikopoiwebpage.h

FORMS    += mainwindow.ui

RC_FILE = idlepoi.rc

OTHER_FILES += \
    idlepoi.rc
