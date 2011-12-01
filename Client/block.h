#ifndef BLOCK_H
#define BLOCK_H
#include <QtGlobal>
//Laitetaan
#pragma pack(1)
typedef quint16 BlockTypeId;

class Block
{
public:
    Block();
    BlockTypeId mBlockTypeId;
    char mBlockData[2];

};
#pragma pack()
Q_DECLARE_TYPEINFO(Block,Q_PRIMITIVE_TYPE);
#endif // BLOCK_H
