#ifndef BLOCKTYPEMANAGER_H
#define BLOCKTYPEMANAGER_H
#include <QMap>
#include "blocktype.h"
#include "block.h"

/**
  * BlockTypeManager hallinnoi BlockTypejä. Se pitää niistä kirjaa ja sisältää funktiot niiden etsimiseen. Ja myöskin lataa BlockTypet
  */
class BlockTypeManager
{
public:
    BlockTypeManager();

    const BlockType *getBlockType(ushort id){Q_ASSERT(mBlockTypes.contains(id));return mBlockTypes.value(id);}
    const BlockType *getBlockType(const Block &block){return getBlockType(block.mBlockType);}
    bool loadBlocks();
private:

    QMap<ushort,BlockType*> mBlockTypes;
};

#endif // BLOCKTYPEMANAGER_H
