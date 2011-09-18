#ifndef OCAUDIOTHREAD_H
#define OCAUDIOTHREAD_H

#include <QThread>
#include "ocmusic.h"
#include <QMutex>

class OCAudioThread : public QThread
{
    Q_OBJECT
public:
    OCAudioThread(QObject *parent = 0);
    ~OCAudioThread();
    void addMusic(OCMusic *music);
    void stop(){mMutex.lock();mRun = false;mMutex.unlock();}
private:
    void run();
    QList<OCMusic*> mPlayList;
    QMutex mMutex;
    bool mRun;
};

#endif // OCAUDIOTHREAD_H
