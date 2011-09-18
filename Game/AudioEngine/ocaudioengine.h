#ifndef OCAUDIOENGINE_H
#define OCAUDIOENGINE_H


#include "al.h"
#include "alc.h"
#include <QList>
#include "ocaudiothread.h"
#include "ocsound.h"
#include "ocmusic.h"




class OCAudioEngine{
public:

    static OCAudioEngine *instance();
    OCSound *createSound();
    void deleteSound(OCSound *sound);

    void addMusic(OCMusic *music);
    void playMusic(OCMusic *music);
private:
    OCAudioEngine();
    ~OCAudioEngine();
    QList<OCSound*> mSounds;
    QList<OCMusic*> mMusics;
    OCAudioThread mThread;
};

#endif // OCAUDIOENGINE_H
