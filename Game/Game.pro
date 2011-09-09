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
    gamescreenstate.cpp \
    blocktype.cpp \
    chunk.cpp \
    chunkvbo.cpp \
    gltexture2d.cpp

HEADERS += \
    glinclude/glinclude.h \
    glpainter.h \
    screenstatemanager.h \
    screenstate.h \
    menuscreenstate.h \
    gamescreenstate.h \
    blocktype.h \
    chunk.h \
    chunkvbo.h \
    gltexture2d.h


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
    chunkfragment.frag \
    chunkvertex.vert











































