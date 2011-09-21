#ifndef CHUNKEDMAP_H
#define CHUNKEDMAP_H
#include "chunk.h"
#include <QList>
#include <QMap>
#include "blocktypemanager.h"
#include "shaderprogrammanager.h"
#include "blocktexturehandler.h"
#include <QGLWidget>

class ChunkedMap
{
public:
    ChunkedMap(QGLWidget *owner);

    BlockTypeManager *blockTypeManager(){return &mBlockTypeManager;}
    ShaderProgramManager *shaderProgramManager(){return &mShaderProgramManager;}
    BlockTextureHandler *textureHandler(){return &mTextureHandler;}
private:
    QMap<ChunkCoord,Chunk*> mChunks;
    BlockTypeManager mBlockTypeManager;
    ShaderProgramManager mShaderProgramManager;
    BlockTextureHandler mTextureHandler;
};

#endif // CHUNKEDMAP_H
