#ifndef CHUNK_H
#define CHUNK_H
#include "chunkvbo.h"
#include <QMutex>
#include "block.h"
#define CHUNK_SIZE 50

class Chunk
{
public:
    Chunk();
    void draw();
    int chunkX()const{return mX;}
    int chunkY()const{return mY;}
    int chunkZ()const{return mZ;}
    Block at(int x,int y,int z)const{return mBlocks[x+y*CHUNK_SIZE+z*CHUNK_SIZE*CHUNK_SIZE];}
private:
    int mX,mY,mZ;
    QMap<BlockTypePtr,QList<BlockCoord> > mBlockTypes;
    Block mBlocks[125000];


    ChunkVBO mVBO;
    QMutex mVBOMutex;
};

#endif // CHUNK_H
