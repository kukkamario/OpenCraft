#ifndef BLOCKTYPEMANAGER_H
#define BLOCKTYPEMANAGER_H
#include <QMap>
#include "blocktype.h"
#include "block.h"

class BlockTypeManager
{
public:
    static const BlockTypeManager *instance();

    const BlockType &getBlockType(const BlockTypePtr &ptr)const{Q_ASSERT(mBlockTypes.contains(ptr));return mBlockTypes.value(ptr);}
    const BlockType &getBlockType(uchar id,uchar secondId = 0)const{BlockTypePtr ptr(id,secondId);return getBlockType(ptr);}
    const BlockType &getBlockType(const Block &block)const{BlockTypePtr ptr(block.mBlockType,block.mBlockType2);return getBlockType(ptr);}
    bool loadBlocks();
private:
    BlockTypeManager();
    QMap<BlockTypePtr,BlockType> mBlockTypes;
};

#endif // BLOCKTYPEMANAGER_H
