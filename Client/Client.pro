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
    mainwindow.cpp \
    glcontext.cpp \
    settingsmenu.cpp \
    multiplayermenu.cpp \
    singleplayermenu.cpp \
    keyinputwidget.cpp \
    controlsettingsmenu.cpp

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
    mainwindow.h \
    glcontext.h \
    settingsmenu.h \
    multiplayermenu.h \
    singleplayermenu.h \
    keyinputwidget.h \
    controlsettingsmenu.h


FORMS += \
    mainmenuwidget.ui \
    settingsmenu.ui \
    multiplayermenu.ui \
    singleplayermenu.ui \
    controlsettingsmenu.ui
























































