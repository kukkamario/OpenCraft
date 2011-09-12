#ifndef BLOCKGROUP_H
#define BLOCKGROUP_H
#include "blocktype.h"
#include "glshaderprogram.h"
class BlockGroup
{
public:
    BlockGroup();
    uchar id()const{return mId;}
    void setId(uchar id){mId = id;}
    void setShaderProgram(glShaderProgram *program){mShaderProgram = program;}
private:
    QList<BlockType*> mBlockTypes;
    glShaderProgram *mShaderProgram;
    uchar mId;
};

#endif // BLOCKGROUP_H
