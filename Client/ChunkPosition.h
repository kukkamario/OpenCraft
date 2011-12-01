#ifndef CHUNKPOSITION_H
#define CHUNKPOSITION_H
#include <QtGlobal>

struct ChunkPosition
{
    ChunkPosition(int x, int y,int z):x(x),y(y),z(z){}
    ChunkPosition():x(0),y(0),z(0){}
    qint32 x,y,z;
};

inline bool operator<(const ChunkPosition &a,const ChunkPosition &b)
{

    return (a.x + a.y + a.z) < (b.x + b.y + b.z);
}

#endif // CHUNKPOSITION_H
