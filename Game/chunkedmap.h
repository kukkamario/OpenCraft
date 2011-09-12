#ifndef CHUNKEDMAP_H
#define CHUNKEDMAP_H
#include "chunk.h"
#include <QList>
#include <QMap>

class ChunkedMap
{
public:
    ChunkedMap();


private:
    QMap<ChunkCoord,Chunk*> mChunks;
};

#endif // CHUNKEDMAP_H
