#-------------------------------------------------
#
# Project created by QtCreator 2011-12-01T15:00:40
#
#-------------------------------------------------

QT       += core gui opengl

CONFIG += precompiled_header
TARGET = Client
TEMPLATE = app
PRECOMPILED_HEADER = pch.h


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
<<<<<<< HEAD
    menustack.cpp \
    mainmenuwidget.cpp

HEADERS  += mainwindow.h \
    game.h \
    menustack.h \
    mainmenuwidget.h

FORMS += \
    mainmenuwidget.ui
=======
    chunkedmap.cpp \
    chunk.cpp \
    block.cpp \
    blockadditionaldata.cpp

HEADERS  += mainwindow.h \
    game.h \
    chunkedmap.h \
    chunk.h \
    pch.h \
    block.h \
    chunkposition.h \
    blockadditionaldata.h











>>>>>>> 06f9d1a28f0bb1664f644ca76330834199d5d5c1







