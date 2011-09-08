#ifndef GL_TEXTURES_H
#define GL_TEXTURES_H

#include <QString>
#include <QImage>
#include "glinclude/glinclude.h"

class glTexture2D{
    private:
        GLuint texture;

    public:
        glTexture2D(const QString &filepath);
        ~glTexture2D();

        void Load(const QString &filepath);
        GLuint get();

        void Bind();

};

#endif
