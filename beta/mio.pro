#-------------------------------------------------
#
# Project created by QtCreator 2018-02-10T21:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += window.h \
    window2.h \
    window3.h \
    window4.h \
    window5.h
SOURCES += main.cpp window.cpp \
    window2.cpp \
    window3.cpp \
    window4.cpp \
    window5.cpp

QT += widgets
QT += core gui
FORMS += \
    window.ui
