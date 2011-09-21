#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H
#include "gltexture2d.h"
#include <QGLWidget>
typedef uchar BlockTextureHandle;

class BlockTextureHandler
{
public:
    BlockTextureHandler(QGLWidget *widget);
    BlockTextureHandle loadTexture(const QString &path);
    GLuint getTexture(BlockTextureHandle id)const{return mTextureArray[id];}

private:
    GLuint mTextureArray[256];
    QGLWidget *mContext;
};

#endif // TEXTUREHANDLER_H
