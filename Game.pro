#-------------------------------------------------
#
# Project created by QtCreator 2014-10-06T22:41:26
#
#-------------------------------------------------

QT       += core gui opengl multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fieldwiget.cpp \
    GroundPlane.cpp

HEADERS  += mainwindow.h \
    fieldwiget.h \
    GroundPlane.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    TankFrag.frag \
    TankVert.vert
