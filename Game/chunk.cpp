#include "chunk.h"
#include "blocktypemanager.h"
#include "glinclude/glinclude.h"
Chunk::Chunk(ChunkedMap *owner)
{
    mOwner = owner;
    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
    {
        mDrawMap[i] = new BlockGroupData;
    }
}


Chunk::~Chunk()
{
    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
    {
        delete mDrawMap[i];
    }
}

void Chunk::draw()
{

}




void Chunk::generateVBOs()
{
    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
    {
        mDrawMap[i]->reset();
    }
    for (int i = 0;i != CHUNK_BLOCK_COUNT;i++)
    {
        Block block = mBlocks[i];
        if (block.mBlockType != 0)
        {
            if (block.mBlockVisibilityFlags != Block::V_Hidden)
            {
                mDrawMap[block.mBlockGroup]->mBlocks.append(mBlocks + i * sizeof(Block));

                mDrawMap[block.mBlockGroup]->mVerticesTotal += BlockTypeManager::instance()->getBlockType(block)->countVertices();
                continue;
            }
        }
    }

    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
    {
        BlockGroupData *drawmap = mDrawMap[i];
        int blocks = drawmap->mBlocks.count();
        if (blocks != 0)
        {
            glGenBuffersARB(1,&(drawmap->mVBO));
            glBindBufferARB(GL_ARRAY_BUFFER_ARB,drawmap->mVBO);

            BlockVertex *vertices = new BlockVertex[drawmap->mVerticesTotal];
            for (QList<Block*>::const_iterator i = drawmap->mBlocks.constBegin();i != drawmap->mBlocks.constEnd();i++)
            {

            }


            glBufferDataARB(GL_ARRAY_BUFFER_ARB,drawmap->mVerticesTotal * sizeof(BlockVertex),vertices,GL_STATIC_DRAW_ARB);
        }
    }
}
