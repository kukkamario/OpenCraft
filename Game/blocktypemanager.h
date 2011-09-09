#ifndef BLOCKTYPEMANAGER_H
#define BLOCKTYPEMANAGER_H
#include "blocktype.h"

class BlockTypeManager
{
public:
    static const BlockTypeManager *instance();

        //Tee toimiva:
    const BlockType &getBlockType(uchar id,uchar secondId = 0)const;
    const BlockType &getBlockType(const BlockTypePtr &ptr)const{return *mBlockTypes;}

    bool loadBlocks();
private:
    BlockTypeManager();
    BlockType *mBlockTypes;
};

#endif // BLOCKTYPEMANAGER_H
