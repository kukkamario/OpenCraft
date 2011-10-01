#include "blocktexturehandler.h"

BlockTextureHandler::BlockTextureHandler(QGLWidget *widget)
{
    memset(mTextureArray,0,sizeof(GLuint)*MAX_TEXTURES);
    mContext = widget;
    mCurrentIndex = 0;
}

GLuint BlockTextureHandler::loadTexture(const QString &path)
{
    Q_ASSERT(mCurrentIndex < MAX_TEXTURES);
    GLuint texture = mContext->bindTexture(path);
    mTextureArray[mCurrentIndex] = texture;
    mCurrectIndex++;
    return texture;
}
