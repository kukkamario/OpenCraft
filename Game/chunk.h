#ifndef CHUNK_H
#define CHUNK_H
#include <QMap>
#include <QMutex>
#include "block.h"
#define CHUNK_SIZE 32
#define CHUNK_BLOCK_COUNT 32768

class Chunk
{
public:
    Chunk();
    void draw();
    int chunkX()const{return mX;}
    int chunkY()const{return mY;}
    int chunkZ()const{return mZ;}
    void organizeBlocks();
    Block at(int x,int y,int z)const{return mBlocks[x+y*CHUNK_SIZE+z*CHUNK_SIZE*CHUNK_SIZE];}
private:
    struct BlockCoord
    {
        uchar x;
        uchar y;
        uchar z;
    };

    struct BlockTypeData
    {
        QList<BlockCoord> mBlocks;
        GLuint mVBO;
    };

    int mX,mY,mZ;
    GLuint mVBO;
    Block mBlocks[CHUNK_BLOCK_COUNT];
};

#endif // CHUNK_H
