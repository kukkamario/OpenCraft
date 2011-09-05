#-------------------------------------------------
#
# Project created by QtCreator 2011-09-01T17:26:36
#
#-------------------------------------------------
CONFIG += qt thread resources

win32{
    CONFIG += windows
}

QT       += core gui opengl

TARGET = Game

TEMPLATE = app


SOURCES += main.cpp \
    glinclude/glinclude.cpp \
    glpainter.cpp \
    screenstatemanager.cpp \
    menuscreenstate.cpp \
    gamescreenstate.cpp

HEADERS += \
    glinclude/glinclude.h \
    glpainter.h \
    screenstatemanager.h \
    screenstate.h \
    menuscreenstate.h \
    gamescreenstate.h


include(../userconfig.pri)



















