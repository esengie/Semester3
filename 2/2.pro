#-------------------------------------------------
#
# Project created by QtCreator 2012-09-18T18:52:37
#
#-------------------------------------------------

QT       += core\
            testlib

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    network.cpp \
    computer.cpp

HEADERS += \
    os.h \
    mac.h \
    wind.h \
    linux.h \
    network.h \
    computer.h \
    networkTest.h
