#-------------------------------------------------
#
# Project created by QtCreator 2011-09-01T17:26:36
#
#-------------------------------------------------

QT       += core gui xml

TARGET = Game

CONFIG += copy_dir_files

TEMPLATE = app


SOURCES += main.cpp \
    glinclude/glinclude.cpp

HEADERS += \
    glinclude/glinclude.h


include(../userconfig.pri)


imedia.path = $$(DESTDIR)/Media
imedia.files = Media
INSTALLS += imedia