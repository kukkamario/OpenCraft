#include "textures.h"

glTexture2D::glTexture2D(const QString &filepath){
    if(filepath!=""){

       QImage tmptex(filepath);

       glGenTextures(1, &texture);
       glBindTexture(GL_TEXTURE_2D, texture);

       glTexImage2D(GL_TEXTURE_2D,
                    0, 3, tmptex.width(), tmptex.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                    tmptex.convertToFormat(QImage::Format_RGB888).constBits()
        );
    }
}

void glTexture2D::Load(const QString &filepath){
    if(filepath!=""){

       QImage tmptex(filepath);

       glGenTextures(1, &texture);
       glBindTexture(GL_TEXTURE_2D, texture);

       glTexImage2D(GL_TEXTURE_2D,
                    0, 3, tmptex.width(), tmptex.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                    tmptex.convertToFormat(QImage::Format_RGB888).constBits()
       );
    }
}

GLuint glTexture2D::get(){
    return texture;
}

