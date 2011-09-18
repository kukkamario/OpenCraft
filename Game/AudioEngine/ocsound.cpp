#include "ocsound.h"

OCSound::OCSound()
{
    mIsNull = true;

}

OCSound::~OCSound()
{
    if (!mIsNull)
    {
        stop();
        alDeleteSources(1,&mSource);
        alDeleteBuffers(1,&mBuffer);
    }
}


void OCSound::play()
{
    Q_ASSERT(mSource);
    alSourcePlay(mSource);
}

void OCSound::stop()
{
    Q_ASSERT(mSource);
    alSourceStop(mSource);
}

bool OCSound::isPlaying()const
{
    Q_ASSERT(mSource);
    int iState;
    alGetSourcei(mSource, AL_SOURCE_STATE, &iState);
    return iState == AL_PLAYING;

}

bool OCSound::load(const QString &path)
{

    //Tähän lataus...


    mIsNull = false;
    return true;
}
