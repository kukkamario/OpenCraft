#include "ocaudiothread.h"

OCAudioThread::OCAudioThread(QObject *parent)
    :QThread(parent)
{
}

OCAudioThread::~OCAudioThread()
{

}

void OCAudioThread::run()
{
    mRun = true;
    forever
    {
        mMutex.lock();

        //Jos ei stopia on kutsuttu lopetetaan suoritus...
        if (!mRun) break;


        int index = 0;
        for (QList<OCMusic*>::iterator i = mPlayList.begin();i != mPlayList.end();i++)
        {
            if (!(*i)->isPlaying())
            {
                mPlayList.removeAt(index);
            }
            else
            {
                (*i)->decodeNext();
                (*i)->playNext();
            }
            index++;
        }

        mMutex.unlock();


        //Odotellaan vähän, että jotain ehtisi tapahtua...
        msleep(10);
    }
}


void OCAudioThread::addMusic(OCMusic *music)
{
    mMutex.lock();
    mPlayList.append(music);
    mMutex.unlock();
}
