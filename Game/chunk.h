#ifndef CHUNK_H
#define CHUNK_H
#include <QMap>
#include <QMutex>
#include "block.h"
#define CHUNK_SIZE 32
#define CHUNK_BLOCK_COUNT 32768

class ChunkedMap;

struct ChunkCoord
{
    int x;
    int y;
    int z;

    bool operator <(const ChunkCoord &coord)const
    {
        return (x+y+z) < (coord.x + coord.y + coord.z);
    }
    bool operator >(const ChunkCoord &coord)const
    {
        return (x+y+z) < (coord.x + coord.y + coord.z);
    }

    bool operator ==(const ChunkCoord &coord)const
    {
        return x==coord.x && y == coord.y && z == coord.z;
    }
};

struct BlockCoord
{
    uchar x;
    uchar y;
    uchar z;
};
class Chunk
{
public:
    Chunk(ChunkedMap *owner){mOwner = owner;}
    void draw();
    ChunkCoord pos()const{mPos;}
    Block at(int x,int y,int z)const{return mBlocks[x+y*CHUNK_SIZE+z*CHUNK_SIZE*CHUNK_SIZE];}
private:
    void generateVBOs();

    struct BlockGroupData
    {
        BlockGroupData(){mVBO = 0;}
        ~BlockGroupData()
        {
            if (mVBO)
            {
                glDeleteBufferARB(1,&mVBO);
            }
        }

        QList<BlockCoord> mBlocks;
        GLuint mVBO;
    };

    QMap<uchar,BlockGroupData> mDrawMap;

    ChunkCoord mPos;
    GLuint mVBO;
    Block mBlocks[CHUNK_BLOCK_COUNT];
    ChunkedMap *mOwner;
};

#endif // CHUNK_H
