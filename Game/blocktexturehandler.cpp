#include "blocktexturehandler.h"

BlockTextureHandler::BlockTextureHandler(QGLWidget *widget)
{
    memset(mTextureArray,0,sizeof(GLuint)*256);
    mContext = widget;
}

BlockTextureHandle BlockTextureHandler::loadTexture(const QString &path)
{
    return 0;
}
