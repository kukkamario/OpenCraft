#include "blocktypemanager.h"

BlockTypeManager::BlockTypeManager()
{
}

const BlockTypeManager *BlockTypeManager::instance()
{
    static BlockTypeManager manager;
    return &manager;
}
