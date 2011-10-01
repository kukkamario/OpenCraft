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
    errorhandler.cpp \
    chunkedmap.cpp \
    ../Public/shaderprogrammanager.cpp \
    mainwindow.cpp \
    screenstate.cpp \
    ocguibutton.cpp \
    AudioEngine/ocaudioengine.cpp \
    AudioEngine/ocaudiothread.cpp \
    ocgui.cpp \
    AudioEngine/ocsound.cpp \
    AudioEngine/ocmusic.cpp \
    ../Public/shaderprogram.cpp \
    blocktexturehandler.cpp

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
    errorhandler.h \
    chunkedmap.h \
    ../Public/shaderprogrammanager.h \
    precompiled_header.h \
    mainwindow.h \
    ocguibutton.h \
    ocguiobject.h \
    AudioEngine/ocaudioengine.h \
    AudioEngine/ocaudiothread.h \
    ocgui.h \
    AudioEngine/ocsound.h \
    AudioEngine/ocmusic.h \
    ../Public/shaderprogram.h \
    blocktexturehandler.h


win32{
    DEFINES += OC_WINDOWS
    DEFINES += FREEGLUT_STATIC
}

CONFIG( debug, debug|release ) {
    LIBS += -L"libs" -lfreeglut_static_d
} else {
    LIBS += -L"libs" -lfreeglut_static
}




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/OpenAL/libs/ -lOpenAL32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/OpenAL/libs/ -lOpenAL32
else:symbian: LIBS += -lOpenAL32
else:unix: LIBS += -L$$PWD/OpenAL/libs/ -lOpenAL32

INCLUDEPATH += $$PWD/OpenAL/include
DEPENDPATH += $$PWD/OpenAL/include
















