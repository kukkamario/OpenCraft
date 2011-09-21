#ifndef BLOCKTYPE_H
#define BLOCKTYPE_H
#include <QString>
#include "glinclude/glinclude.h"
#include "blockvertex.h"
#include "shaderprogrammanager.h"
#include "blocktexturehandler.h"


/**
  * Palikkatyyppi. Kaikkilla eri muotoisilla ja näköisillä blockeilla on oma BlockTypensä.

  * @brief
  *  BlockTypet erotetaan toisistaan id:n avulla. Id generoidaan joka kartan luonnin yhteydessä ja tallennetaan karttatiedostoon.
  *  BlockType pitää myös sisällää tarvittavan tiedon palikan piirtämiseen.
  */
class BlockType
{
public:
    BlockType();
    void setIndex(ushort index){mIndex = index;}
    ushort index()const{return mIndex;}
    void setName(const QString &name){mName = name;}
    QString name()const{return mName;}
    void setVertexVBO(GLuint vbo){mVertexVBO = vbo;}
    void setIndexVBO(GLuint vbo){mIndexVBO = vbo;}
    GLuint vertexVBO()const{return mVertexVBO;}
    GLuint indexVBO()const{return mIndexVBO;}
    void setIndexCount(int count){mIndexCount = count;}
    int indexCount()const{return mIndexCount;}
    /**
      * Joko GL_TRIAGLES tai GL_QUADS
      */
    void setDrawMode(GLenum m){mDrawMode = m;}
    GLenum drawMode()const{return mDrawMode;}

    /**
      * Joko GL_UNSIGNED_BYTE tai GL_UNSIGNED_SHORT
      */
    void setIndexType(GLenum i){mIndexType = i;}
    GLenum indexType()const{return mIndexType;}


    bool isAir()const{return mIsAir;}
    ShaderProgramHandle shaderProgram()const{return mShaderProgram;}
    BlockTextureHandle texture()const{return mTexture;}
private:
    QString mName;
    ushort mIndex;
    GLuint mVertexVBO;
    GLuint mIndexVBO;
    int mIndexCount;
    GLenum mDrawMode;
    GLenum mIndexType;
    ShaderProgramHandle mShaderProgram;
    BlockTextureHandle mTexture;
    bool mIsAir;
};

#endif // BLOCKTYPE_H
