#include "gltexture2d.h"

glTexture2D::glTexture2D(const QString &filepath, bool mipmap)
{
    texture = 0;
    load(filepath,mipmap);
}

glTexture2D::~glTexture2D()
{
    unload();
}

void glTexture2D::unload()
{
    if (texture) glDeleteTextures(1,&texture);
    texture = 0;
}


void glTexture2D::load(const QString &filepath, bool mipmap)
{

    unload();
    QImage tmptex(filepath);
    if (tmptex.isNull()) return;//virhe ladatessa...

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    if (!tmptex.hasAlphaChannel()) //Valitaan alfakanavan olemassa olon mukaan sopiva muoto...
    {
        qDebug("RGB");
        if (mipmap)
        {
            gluBuild2DMipmaps(GL_TEXTURE_2D,3,tmptex.width(),tmptex.height(),GL_RGB,GL_UNSIGNED_BYTE,tmptex.convertToFormat(QImage::Format_RGB888).constBits());
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D,
                    0, 3, tmptex.width(), tmptex.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                    tmptex.convertToFormat(QImage::Format_RGB888).constBits());
        }
    }
    else
    {
        qDebug("RGBA");
        //Muunnos ARGB:st‰ RGBA:ksi
        tmptex = tmptex.convertToFormat(QImage::Format_ARGB32);
        uchar *dataptr = tmptex.bits();
        int pixels = tmptex.width()*tmptex.height();
        for (int i = 0; i != pixels; i++)
        {
            uchar alpha = *dataptr; //otetaan alfa arvo...
            *dataptr = dataptr[1]; //siirret‰‰n muita v‰ri arvoja datassa 1 eteenp‰in...
            dataptr[1] = dataptr[2];
            dataptr[2] = dataptr[3];
            dataptr[3] = alpha; //laitetaan alfalle oikea arvo
            dataptr+= 4; //ja seuraavaan pikseliin...
        }

        if (mipmap)
        {
            gluBuild2DMipmaps(GL_TEXTURE_2D,4,tmptex.width(),tmptex.height(),GL_RGBA,GL_UNSIGNED_BYTE,tmptex.constBits());
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D,
                    0, 4, tmptex.width(), tmptex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,
                    tmptex.constBits());
        }
    }
}

