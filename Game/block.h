#ifndef BLOCK_H
#define BLOCK_H
#include "blocktype.h"

class Block
{
public:
    Block(){}
    uchar mBlockType;
    char mOtherData[3];
};

#endif // BLOCK_H
