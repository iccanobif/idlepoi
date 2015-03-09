#-------------------------------------------------
#
# Project created by QtCreator 2012-02-12T21:23:28
#
#-------------------------------------------------

VERSION = 1.0.3

QT       += core gui webkit network

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
