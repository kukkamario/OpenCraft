#ifndef CHUNKEDMAP_H
#define CHUNKEDMAP_H

#include <QObject>
#include "chunkposition.h"
#include <QMap>
#include "chunk.h"

class ChunkedMap : public QObject
{
    Q_OBJECT
public:
    explicit ChunkedMap(QObject *parent = 0);


signals:

public slots:

private:
    QMap<ChunkPosition,Chunk*> mChunks;

};

#endif // CHUNKEDMAP_H
