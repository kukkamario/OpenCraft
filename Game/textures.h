#ifndef GL_TEXTURES_H
#define GL_TEXTURES_H

#include <QString>
#include <QImage>
#include "glinclude/freeglut.h"

class glTexture2D{
    private:
        GLuint texture;

    public:
        glTexture2D(QString filepath);
        ~glTexture2D();

        void Load(QString filepath);
        GLuint get();

};

#endif
