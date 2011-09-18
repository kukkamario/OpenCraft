#ifndef OCMUSIC_H
#define OCMUSIC_H
#include <QString>

/**
  * OCMusic on abstrakti luokka musiikkeja varten. Sille pitäisi tehdä alaluokka Ogg:ta varten (OCMusicOgg?)
  * Alaluokkien on oltava thread-safe, niin että OCAudioThread voi toistaa niitä
  */
class OCAudioEngine;
class OCAudioThread;

class OCMusic
{
    friend class OCAudioEngine;
    friend class OCAudioThread;

public:
    virtual bool isPlaying() = 0;

    /**
      * Alustaa musiikin tiedostosta
      */
    virtual bool load(const QString path) = 0;

    virtual QString name() = 0;
protected:
    OCMusic();
    ~OCMusic();

    /**
      * Näitä kutsutaan OCAudioEnginen playMusic funktiossa...
      */
    virtual void play() = 0;
    virtual void stop() = 0;

    /**
     * Purkaa puskuriin uutta dataa
     */
    virtual void decodeNext() = 0;

    /**
     * Soittaa datan puskurista. Kutsutaan aina decodeNextin jälkeen
     */
    virtual void playNext() = 0;
};

#endif // OCMUSIC_H
