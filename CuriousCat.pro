#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T16:19:37
#
#-------------------------------------------------

QT       += core gui \
            network \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QTPLUGIN += dsengine qtmedia_audioengine
TARGET = CuriousCat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    danger.cpp \
    gamemodel.cpp \
    background.cpp \
    event.cpp \
    highscore.cpp \
    object.cpp \
    sound.cpp

HEADERS  += mainwindow.h \
    danger.h \
    gamemodel.h \
    background.h \
    event.h \
    object.h \
    highscore.h \
    sound.h

FORMS    += mainwindow.ui

RESOURCES += \
    Images/resources.qrc \
    Images/resources.qrc
QMAKE_CXXFLAGS += -std=c++11

