#include "tesselator.h"

Tesselator::Tesselator()
    :mBuffer(QGLBuffer::VertexBuffer)
{

}

Tesselator::~Tesselator()
{
}

Tesselator::init()
{
    mBuffer.create();
}
Tesselator::destroy()
{
    mBuffer.destroy();
}

Tesselator::begin(GLenum mode)
{
    mDrawMode = mode;
    mIndex = 0;
}

