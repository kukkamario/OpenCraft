#ifndef BLOCKTYPE_H
#define BLOCKTYPE_H
#include <QString>
#include "glinclude/glinclude.h"
#include "blockvertex.h"


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
    ushort index()const{return mIndex;}
    QString name()const{return mName;}
    GLuint vbo()const{return mVBO;}
private:
    QString mName;
    ushort mIndex;
    GLuint mVBO;
};

#endif // BLOCKTYPE_H
