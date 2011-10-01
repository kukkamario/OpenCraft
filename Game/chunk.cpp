#include "chunk.h"
#include "blocktypemanager.h"
#include "glinclude/glinclude.h"
#include "chunkedmap.h"
#include "shaderprogrammanager.h"
#define BLOCK_SIZE 1.0f


class DummyClass
{
    DummyClass()
    {

    }
};


Chunk::Chunk(ChunkedMap *owner)
{
    mOwner = owner;
}


Chunk::~Chunk()
{
}

void Chunk::draw()
{
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);
//    glEnableClientState(GL_NORMAL_ARRAY);
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    ShaderProgramHandle ptr = INVALID_SHADER_PROGRAM_PTR;
    ShaderProgram *shaderProgram = 0;
    GLuint texture = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    for (int i = 1;i != MAX_BLOCK_GROUP_DATAS;i++)
    {
        if (mBlocks[i].mBlockVisibilityFlags != Block::V_Hidden)
        {
            const BlockType *blockType = this->mOwner->blockTypeManager()->getBlockType(mBlocks[i]);
            if (blockType->shaderProgram() != ptr)
            {
                ptr = blockType->shaderProgram();
                shaderProgram = mOwner->shaderProgramManager()->find(ptr);
                //Valitaa shaderi käytettäväksi
                shaderProgram->bind();

                //Hoidetaan että shadereiden attribuutit saavat oikeat arvot
                glVertexAttribPointer(GLSL_POS_VERTEX_COORDS,4,GL_FLOAT,GL_FALSE,24,(void*)0);
                glVertexAttribPointer(GLSL_POS_COLOR,4,GL_UNSIGNED_BYTE,GL_FALSE,36,(void*)16);
                glVertexAttribPointer(GLSL_POS_TEXTURE_COORDS,2,GL_FLOAT,GL_FALSE,32,(void*)20);
                glVertexAttribPointer(GLSL_POS_NORMAL,3,GL_FLOAT,GL_FALSE,28,(void*)28);

            }
            if (blockType->texture() != texture)
            {
                glBindTexture(blockType->texture());
                texture = blockType->texture();
            }

            glBindBufferARB(GL_ARRAY_BUFFER_ARB, blockType->vertexVBO());//Lista pisteistä ja väreistä
            glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, blockType->indexVBO()); // indeksit pisteisiin
            glDrawElements(blockType->drawMode(), blockType->indexCount(), blockType->indexType(), 0);
        }
    }
}


