#-------------------------------------------------
#
# Project created by QtCreator 2011-11-14T16:31:05
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = InstancingTest
CONFIG += console
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    noise.cpp

HEADERS  += mainwindow.h \
    noise.h \
    defines.h

OTHER_FILES += \
    vertex.vert \
    fragment.frag \
    texture.png

RESOURCES += \
    resource.qrc











