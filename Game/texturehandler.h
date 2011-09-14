#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H
#include "gltexture2d.h"
typedef uchar TextureHandle;

class TextureHandler
{
public:
    TextureHandler();
    uchar loadTexture(const QString &path);
};

#endif // TEXTUREHANDLER_H
