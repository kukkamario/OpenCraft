#ifndef OCSOUND_H
#define OCSOUND_H
#include "al.h"
#include <QReadWriteLock>
class OCAudioThread;
class OCAudioEngine;


/**
  * OCSound on luokka kerralla kokonaan muistiin ladattavia ‰‰ni‰ varten.
  */
class OCSound
{
    //N‰m‰ merkataan kavereiksi, ett‰ voivat k‰ytt‰‰ privaatteja muuttujia/funktioita
    friend class OCAudioThread;
    friend class OCAudioEngine;


public:
    bool load(const QString &path);
    bool isPlaying()const;
    void play();
    void stop();


    /**
      * T‰‰ll‰ pit‰isi pysty‰ varmistamaan onko ‰‰ni ladattu vai ei.
      */
    bool isNull();
private:
    //Private ett‰ vain AudioEngine voi luoda
    OCSound();
    //ja poistaa
    ~OCSound();

    ALuint mBuffer;
    ALuint mSource;
    bool mIsNull;
};

#endif // OCSOUND_H
