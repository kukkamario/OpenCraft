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
    game.cpp \
    menustack.cpp \
    mainmenuwidget.cpp \
    chunkedmap.cpp \
    chunk.cpp \
    block.cpp \
    blockadditionaldata.cpp \
    mainwindow.cpp

HEADERS  += \
    game.h \
    chunkedmap.h \
    chunk.h \
    pch.h \
    block.h \
    chunkposition.h \
    blockadditionaldata \
    mainmenuwidget.h \
    blockadditionaldata.h \
    menustack.h \
    mainwindow.h


FORMS += \
    mainmenuwidget.ui

























