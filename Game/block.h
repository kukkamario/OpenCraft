#ifndef BLOCK_H
#define BLOCK_H
#include "blocktype.h"


class Block
{
public:
    enum VisibilityFlags
    {
        V_Hidden = 0x00,
        V_Left = 0x01,
        V_Right = 0x02,
        V_Front = 0x04,
        V_Back = 0x08,
        V_Top = 0x10,
        V_Bottom = 0x20,
        V_Transparent = 0x40
    };

    Block(){}
    uchar mBlockType;
    uchar mBlockType2;
    uchar mBlockVisibilityFlags;
    uchar mLight;
    uchar mBlockGroup;
    char mBlockTypeData[2];
};

#endif // BLOCK_H
