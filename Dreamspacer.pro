#-------------------------------------------------
#
# Project created by QtCreator 2016-01-27T21:35:10
#
#-------------------------------------------------

QT       += core gui webkit  webkitwidgets widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dreamspacer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    global.cpp \
    debug.cpp \
    sec.cpp \
    vkapi_types.cpp \
    vkapi.cpp

HEADERS  += mainwindow.h \
    global.h \
    debug.h \
    sec.h \
    vkapi_types.h \
    vkapi.h

FORMS    += mainwindow.ui

CONFIG += c++11
