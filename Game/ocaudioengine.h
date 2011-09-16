#ifndef OCAUDIOENGINE_H
#define OCAUDIOENGINE_H


#include "al.h"
#include "alc.h"

class OCAudioEngine{
    ALuint mBuffer;
    ALuint mSource;

public:
    OCAudioEngine();

};

#endif // OCAUDIOENGINE_H
