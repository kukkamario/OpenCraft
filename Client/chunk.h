#ifndef CHUNK_H
#define CHUNK_H

#include <QObject>
#include <QGLBuffer>
#include "block.h"
#include <QDataStream>
#include <QMap>
#include "blockadditionaldata.h"


class ChunkedMap;

#define CHUNK_SIZE 32


class Chunk : public QObject
{
    Q_OBJECT
public:
    //Alustaa Chunkin ja t‰ytt‰‰ sen ilmalla
    Chunk(ChunkedMap *parent);
    Chunk(QDataStream *s,ChunkedMap *parent);

    /**
      *Palauttaa chunkin versio numeron. K‰ytet‰‰n monipeliss‰ est‰m‰‰n turhaa chunkin datan uudelleen latausta serverilt‰.
      */
    quint32 versionNumber()const{return mVersionNumber;}

    void writeChunkDataCompressed(QDataStream &s,int compressionLevel = 5);
    Block &blockAt(int x,int y,int z){return mBlockData[x + y*CHUNK_SIZE + z * CHUNK_SIZE*CHUNK_SIZE];}

signals:

public slots:


private:
    quint32 mVersionNumber;
    bool mJustAir; //Onko chunk pelkk‰‰ ilmaa?
    Block mBlockData[CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE];


    QMap<BAD_id,BlockAdditionalData*> mBADDatas;
};



#endif // CHUNK_H
