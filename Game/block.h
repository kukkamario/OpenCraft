#ifndef BLOCK_H
#define BLOCK_H
#include "blocktype.h"


class Block
{
public:
    enum Flags
    {
        V_Left = 0x01,
        V_Right = 0x02,
        V_Front = 0x04,
        V_Back = 0x08,
        V_Top = 0x10,
        V_Bottom = 0x20
    };

    Block(){}
    uchar mBlockType;
    uchar mBlockType2;
    uchar mBlockFlags;
    char mBlockTypeData[2];
};

#endif // BLOCK_H