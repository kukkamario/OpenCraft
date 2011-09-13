#ifndef CHUNKEDMAP_H
#define CHUNKEDMAP_H
#include "chunk.h"
#include <QList>
#include <QMap>
#include "blocktypemanager.h"
#include "shaderprogrammanager.h"

class ChunkedMap
{
public:
    ChunkedMap();

    BlockTypeManager *blockTypeManager(){return &mBlockTypeManager;}
    ShaderProgramManager *shaderProgramManager(){return &mShaderProgramManager;}
private:
    QMap<ChunkCoord,Chunk*> mChunks;
    BlockTypeManager mBlockTypeManager;
    ShaderProgramManager mShaderProgramManager;
};

#endif // CHUNKEDMAP_H
