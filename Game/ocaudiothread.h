#ifndef OCAUDIOTHREAD_H
#define OCAUDIOTHREAD_H

#include <QThread>
#include "ocaudioengine.h"

class OCAudioThread : public QThread{

public:
    OCAudioThread();
};

#endif // OCAUDIOTHREAD_H
