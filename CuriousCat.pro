#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T16:19:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CuriousCat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    danger.cpp \
    gamemodel.cpp \
    background.cpp \
    event.cpp

HEADERS  += mainwindow.h \
    danger.h \
    gamemodel.h \
    background.h \
    event.h \
    object.h

FORMS    += mainwindow.ui

RESOURCES += \
    Images/resources.qrc
