#include "ocaudioengine.h"

OCAudioEngine::OCAudioEngine()
{

}

OCAudioEngine::~OCAudioEngine()
{
    for (QList<OCSound*>::iterator i = mSounds.begin();i != mSounds.end();i++)
    {
        delete *i;
    }

    for (QList<OCMusic*>::iterator i = mMusics.begin();i != mMusics.end();i++)
    {
        delete *i;
    }
}

OCAudioEngine *OCAudioEngine::instance()
{
    static OCAudioEngine mEngine;
    return &mEngine;
}

OCSound *OCAudioEngine::createSound()
{
    OCSound *sound = new OCSound;
    mSounds.append(sound);
    return sound;
}

void OCAudioEngine::deleteSound(OCSound *sound)
{
    mSounds.removeOne(sound);
    delete sound;
}


void OCAudioEngine::addMusic(OCMusic *music)
{
    mMusics.append(music);
}

void OCAudioEngine::playMusic(OCMusic *music)
{
    if (!mThread.isRunning()) mThread.start();
    music->play();
    mThread.addMusic(music);
}
