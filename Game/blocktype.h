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
    QString name()const;
    int countVertices()const{return mVertexCount;}
    const BlockVertex *getVertices()const{return mVertices;}
private:
    QString mName;
    ushort mIndex;
    int mVertexCount;
    BlockVertex *mVertices;
};

#endif // BLOCKTYPE_H
