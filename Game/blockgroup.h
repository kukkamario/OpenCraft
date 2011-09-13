#ifndef BLOCKGROUP_H
#define BLOCKGROUP_H
#include "blocktype.h"
#include <QGLShaderProgram>
#include "gltexture2d.h"

/**
  * BlockGroupeihin lajitellaan kaikki blockit sen mukaan,miten ne piirret‰‰n.

  * @brief
  * BlockGroupiin kuuluvat BlockTypet voidaan piirt‰‰ samalla kertaa, koska ne k‰ytt‰v‰t samaa tekstuuria ja shadereita.
  * Maksimi BlockGroupien m‰‰r‰ on rajattu 255:n. (0:lla on varattu ilmalle)

  */

class BlockGroup
{
public:
    BlockGroup();
    uchar id()const{return mId;}
    void setId(uchar id){mId = id;}
    bool contains(BlockType *bt) const{return mBlockTypes.contains(bt);}
    void addBlockType(BlockType *bt){mBlockTypes.append(bt);}
    void setShaderProgram(QGLShaderProgram *program){mShaderProgram = program;}
private:
    QList<BlockType*> mBlockTypes;
    QGLShaderProgram *mShaderProgram;
    glTexture2D mTexture;
    uchar mId;
};

#endif // BLOCKGROUP_H
