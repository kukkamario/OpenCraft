#ifndef CHUNK_H
#define CHUNK_H
#include "chunkvbo.h"
#include <QMutex>

class Chunk
{
public:
    Chunk();
    void draw();
private:
    int mX,mY,mZ;

    ChunkVBO mVBO;
    QMutex mVBOMutex;
};

#endif // CHUNK_H
