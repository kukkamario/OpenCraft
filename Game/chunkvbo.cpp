#include "chunkvbo.h"
#include "blocktypemanager.h"

ChunkVBO::ChunkVBO()
{
}

void ChunkVBO::draw()
{

}

void ChunkVBO::generate(const QMap<BlockTypePtr, QList<BlockCoord> > &map)
{
    for  (QMap<BlockTypePtr, QList<BlockCoord> >::const_iterator i = map.constBegin();i != map.constEnd();i++)
    {
        QList<BlockCoord> blockCoords = i.value();
        BlockType blockType = BlockTypeManager::instance()->getBlockType(i.key());
        //Kesken
    }
}
