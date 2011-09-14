#ifndef CHUNK_H
#define CHUNK_H
#include <QMap>
#include <QMutex>
class QGLShaderProgram;
#include "block.h"
#define CHUNK_SIZE 32
#define CHUNK_BLOCK_COUNT 32768
#define MAX_BLOCK_GROUP_DATAS 256

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

//struct BlockGroupData
//{
//    struct BlockPosData
//    {
//        Block* ptr;
//        uchar x;
//        uchar y;
//        uchar z;
//    };

//    BlockGroupData(){mVBO = 0;}
//    ~BlockGroupData()
//    {
//        if (mVBO)
//        {
//            glDeleteBufferARB(1,&mVBO);
//        }
//    }
//    void reset()
//    {
//        if (mVBO)
//        {
//            glDeleteBufferARB(1,&mVBO);
//        }
//    }
//    QList<Block*> mBlocks;
//    GLuint mVBO;
//    int mVerticesTotal;
//    QGLShaderProgram *mShaderProgram;
//};

struct BlockCoord
{
    uchar x;
    uchar y;
    uchar z;
};
class Chunk
{
public:
    Chunk(ChunkedMap *owner);
    ~Chunk();

    void draw();
    ChunkCoord pos()const{mPos;}
    Block at(int x,int y,int z)const{return mBlocks[x+y*CHUNK_SIZE+z*CHUNK_SIZE*CHUNK_SIZE];}
private:
    //void generateVBOs();

    ChunkCoord mPos;
    Block mBlocks[CHUNK_BLOCK_COUNT];
    ChunkedMap *mOwner;
};

#endif // CHUNK_H
