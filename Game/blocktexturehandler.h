#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H
#include "gltexture2d.h"
#include <QGLWidget>
#define MAX_TEXTURES 256

class BlockTextureHandler
{
public:
    BlockTextureHandler(QGLWidget *widget);
    ~BlockTextureHandler();
    GLuint loadTexture(const QString &path);
private:
    GLuint mTextureArray[MAX_TEXTURES];
    QGLWidget *mContext;
    int mCurrentIndex;
};

#endif // TEXTUREHANDLER_H
