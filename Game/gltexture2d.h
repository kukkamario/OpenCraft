#ifndef GL_TEXTURES_H
#define GL_TEXTURES_H

#include <QString>
#include <QImage>
#include "glinclude/glinclude.h"

class glTexture2D{
private:
    GLuint texture;

public:
    glTexture2D(){texture = 0;}
    glTexture2D(const QString &filepath,bool mipmap = true);
    ~glTexture2D();

    void load(const QString &filepath,bool mipmap = true);
    GLuint getId(){return texture;}
    void bind()const{Q_ASSERT(texture);glBindTexture(GL_TEXTURE_2D,texture);}
    bool isNull()const{return texture == 0;}
    void unload();
};

#endif
