#-------------------------------------------------
#
# Project created by QtCreator 2011-09-01T17:26:36
#
#-------------------------------------------------
CONFIG += qt thread resources precompile_header

win32{
    CONFIG += windows
}

QT       += core gui opengl

TARGET = Game


TEMPLATE = app

PRECOMPILED_HEADER += precompiled_header.h

SOURCES += main.cpp \
    glinclude/glinclude.cpp \
    glpainter.cpp \
    screenstatemanager.cpp \
    menuscreenstate.cpp \
    gamescreenstate.cpp \
    blocktype.cpp \
    chunk.cpp \
    gltexture2d.cpp \
    blocktypemanager.cpp \
    blockgroup.cpp \
    errorhandler.cpp \
    chunkedmap.cpp \
    shaderprogrammanager.cpp \
    mainwindow.cpp \
    screenstate.cpp

HEADERS += \
    glinclude/glinclude.h \
    glpainter.h \
    screenstatemanager.h \
    screenstate.h \
    menuscreenstate.h \
    gamescreenstate.h \
    blocktype.h \
    chunk.h \
    gltexture2d.h \
    blocktypemanager.h \
    blockvertex.h \
    block.h \
    blockgroup.h \
    errorhandler.h \
    chunkedmap.h \
    shaderprogrammanager.h \
    precompiled_header.h \
    mainwindow.h


win32{
    DEFINES += OC_WINDOWS
    DEFINES += FREEGLUT_STATIC
}

CONFIG( debug, debug|release ) {
    LIBS += -L"libs" -lfreeglut_static_d
} else {
    LIBS += -L"libs" -lfreeglut_static
}

OTHER_FILES += \
    shaders/chunkfragment.frag \
    shaders/chunkvertex.vert









































































