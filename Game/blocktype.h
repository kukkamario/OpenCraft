#ifndef BLOCKTYPE_H
#define BLOCKTYPE_H
#include <QString>
#include "glinclude/glinclude.h"
#include "blockvertex.h"
class BlockTypePtr
{
public:
    BlockTypePtr(uchar index,uchar index2 = 0):mIndex(index),mIndex2(index2){}
    bool operator == (const BlockTypePtr &ptr)const
    {
        return (mIndex == ptr.mIndex) && (mIndex2 == ptr.mIndex2);
    }

    bool operator <(const BlockTypePtr &ptr)const
    {
        return (((int)mIndex << 16)+mIndex2) < (((int)ptr.mIndex << 16)+ptr.mIndex2);
    }

    bool operator >(const BlockTypePtr &ptr)const
    {
        return (((int)mIndex << 16)+mIndex2) < (((int)ptr.mIndex << 16)+ptr.mIndex2);
    }

    uchar mIndex;
    uchar mIndex2;
};

class BlockType
{
public:
    BlockType();
    uchar index()const{return mIndex;}
    uchar index2()const{return mIndex2;}
    bool hasSecondIndex()const{return mSecondIndex;}
    BlockTypePtr ptr()const{return BlockTypePtr(mIndex,mIndex2);}
    QString name()const;
    int countVertices()const{return mVertexCount;}
    const BlockVertex *getVertices()const{return mVertices;}
private:
    QString mName;
    uchar mIndex;
    bool mSecondIndex;
    uchar mIndex2;
    int mVertexCount;
    BlockVertex *mVertices;
};

#endif // BLOCKTYPE_H
