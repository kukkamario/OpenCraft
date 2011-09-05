#ifndef BLOCKTYPE_H
#define BLOCKTYPE_H
#include <QString>
#include "glinclude/glinclude.h"

class BlockType
{
public:
    BlockType();
    virtual QString name() = 0;
};

#endif // BLOCKTYPE_H
