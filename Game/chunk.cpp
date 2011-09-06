#include "chunk.h"

Chunk::Chunk()
{
}

void Chunk::draw()
{
    mVBOMutex.lock();
    mVBO.draw();
    mVBOMutex.unlock();
}
