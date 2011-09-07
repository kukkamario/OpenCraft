#include "textures.h"

glTexture2D::glTexture2D(QString filepath){
    if(filepath!=""){

       QImage tmptex(filepath);

       glGenTextures(1, &texture);
       glBindTexture(GL_TEXTURE_2D, texture);

       glTexImage2D(GL_TEXTURE_2D,
                    0, 3, tmptex.width(), tmptex.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                    tmptex.convertToFormat(QImage::Format_ARGB32).constBits()
        );
    }
}

void glTexture2D::Load(QString filepath){
    if(filepath!=""){

       QImage tmptex(filepath);

       glGenTextures(1, &texture);
       glBindTexture(GL_TEXTURE_2D, texture);

       glTexImage2D(GL_TEXTURE_2D,
                    0, 3, tmptex.width(), tmptex.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                    tmptex.convertToFormat(QImage::Format_ARGB32).constBits()
       );
    }
}

GLuint glTexture2D::get(){
    return texture;
}

