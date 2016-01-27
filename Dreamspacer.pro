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
    vkapi.cpp \
    global.cpp \
    debug.cpp

HEADERS  += mainwindow.h \
    global.h \
    vkapi.h \
    debug.h

FORMS    += mainwindow.ui
