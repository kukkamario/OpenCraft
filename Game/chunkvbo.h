#ifndef CHUNKVBO_H
#define CHUNKVBO_H
#include "glinclude/glinclude.h"
#include <QMap>
#include "block.h"
#include "blocktype.h"
struct BlockCoord
{
    uchar x;
    uchar y;
    uchar z;
};
class ChunkVBO
{
public:
    ChunkVBO();
    void generate(const QMap<BlockTypePtr,QList<BlockCoord> > & map);
    void draw();
private:
    QMap<BlockTypePtr,GLuint> mVBOs;
};

#endif // CHUNKVBO_H
