#ifndef BLOCKADDITIONALDATA_H
#define BLOCKADDITIONALDATA_H
#include <QtGlobal>
#include <QDataStream>
typedef quint16 BAD_id;

/**
  * Tallentaa sellaisten blockien ylim‰‰r‰isen datan, joka ei mahdu perus blockiin, esim. arkku.
  * Tiedot haetaan id:ll‰ Chunkissa olevasta QMapista.
  * Arkun ja muille t‰ll‰isille blockeille tehd‰‰n omat BlockAdditionalData:n alaluokat.
  */


class BlockAdditionalData
{
public:
    BlockAdditionalData(BAD_id id);
    BAD_id id()const{return mId;}
    virtual void write(QDataStream &s) = 0;
protected:
    BAD_id mId;
};

#endif // BLOCKADDITIONALDATA_H
