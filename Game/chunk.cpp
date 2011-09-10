#include "chunk.h"
#include "blocktypemanager.h"
#include "glinclude/glinclude.h"

Chunk::Chunk()
{
}

void Chunk::draw()
{

}

void Chunk::organizeBlocks()
{
    mBlockTypes.clear();
    for (int z = 0;z != CHUNK_SIZE;z++)
    {
        for (int y = 0;y != CHUNK_SIZE;y++)
        {
            for (int x = 0;x != CHUNK_SIZE;x++)
            {
                Block block = mBlocks[x+y*CHUNK_SIZE+z*CHUNK_SIZE*CHUNK_SIZE];
                BlockTypePtr ptr(block.mBlockType,block.mBlockType2);
                mBlockTypes[ptr].append(block);
            }
        }
    }
}


void Chunk::generateVBOs()
{
    for  (QMap<BlockTypePtr, QList<BlockCoord> >::const_iterator i = map.constBegin();i != map.constEnd();i++)
    {
        QList<BlockCoord> blockCoords = i.value();
        BlockType blockType = BlockTypeManager::instance()->getBlockType(i.key());


    }
}
