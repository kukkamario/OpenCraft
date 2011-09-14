#include "chunk.h"
#include "blocktypemanager.h"
#include "glinclude/glinclude.h"
#include "chunkedmap.h"
#include "shaderprogrammanager.h"
#define BLOCK_SIZE 1.0f




Chunk::Chunk(ChunkedMap *owner)
{
    mOwner = owner;
}


Chunk::~Chunk()
{
}

void Chunk::draw()
{
    ShaderProgramHandle ptr = INVALID_SHADER_PROGRAM_PTR;
    QGLShaderProgram *shaderProgram = 0;
    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
    {
        if (mBlocks[i].mBlockVisibilityFlags != Block::V_Hidden)
        {
            if (mBlocks[i].mShaderProgram != ptr)
            {
                shaderProgram = mOwner->shaderProgramManager()->find(ptr);
                shaderProgram->bind();
            }

        }
    }
}




//void Chunk::generateVBOs()
//{
//    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
//    {
//        mDrawMap[i]->reset();
//    }
//    for (int i = 0;i != CHUNK_BLOCK_COUNT;i++)
//    {
//        Block block = mBlocks[i];
//        if (block.mBlockType != 0)
//        {
//            if (block.mBlockVisibilityFlags != Block::V_Hidden)
//            {
//                mDrawMap[block.mBlockGroup]->mBlocks.append(mBlocks + i * sizeof(Block));

//                mDrawMap[block.mBlockGroup]->mVerticesTotal += mOwner->blockTypeManager()->getBlockType(block)->countVertices();
//                continue;
//            }
//        }
//    }

//    for (int i = 0;i != MAX_BLOCK_GROUP_DATAS;i++)
//    {
//        BlockGroupData *drawmap = mDrawMap[i];
//        int blocks = drawmap->mBlocks.count();
//        if (blocks != 0)
//        {
//            glGenBuffersARB(1,&(drawmap->mVBO));
//            glBindBufferARB(GL_ARRAY_BUFFER_ARB,drawmap->mVBO);

//            BlockVertex *vertices = new BlockVertex[drawmap->mVerticesTotal];
//            for (QList<Block*>::const_iterator i = drawmap->mBlocks.constBegin();i != drawmap->mBlocks.constEnd();i++)
//            {

//            }


//            glBufferDataARB(GL_ARRAY_BUFFER_ARB,drawmap->mVerticesTotal * sizeof(BlockVertex),vertices,GL_STATIC_DRAW_ARB);
//        }
//    }
//}
