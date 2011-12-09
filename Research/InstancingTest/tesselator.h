#ifndef TESSELATOR_H
#define TESSELATOR_H
#include <GL/GL.h>
#include <QGLBuffer>
#include <qmath.h>
#include "defines.h"

#pragma pack(1)
struct VertexData
{
    float x,y,z;//0
    float tx,ty,tz;//12
    char nx,ny,nz,align;//24
    float light; //28
};
#pragma pack()

class Tesselator
{
public:
    Tesselator();
    ~Tesselator();
    void setLightingData(float *data);
    void init();
    void destroy();
    void begin(GLenum mode);
    void endAndDraw();
    void addTexCoord(double x,double y,double z){mTX = x;mTY = y;mTZ = z;}
    void addNormal(double x,double y,double z){mNX = x*127.0;mNY = y*127.0;mNZ = z*127.0;}
    void addVertex(double x,double y,double z);

    inline void transform(const double x,const double y,const double z);

private:
    QGLBuffer mBuffer;
    VertexData * mDataBuffer;
    int mDataBufferSize;
    unsigned int mIndex;
    GLenum mDrawMode;
    double mTX,mTY,mTZ;
    char mNX,mNY,mNZ;
    float interpolateLight(double x,double y,double z);
    float mLightingData;

};


Tesselator::transform(const double x,const double y,const double z)
{
    mTX += x;
    mTY += y;
    mTZ += z;
}

float Tesselator::interpolateLight(double x, double y, double z)
{
    int pickX = x+mNX*0.5;
    int pickY = y+mNY*0.5;
    int pickZ = z+mNZ*0.5;
    return mLightingData[pickX + pickY *(MAP_SIZE+2) + pickZ * (MAP_SIZE+2)*(MAP_SIZE+2)];
    /*
    double pickX = x+mTX*0.5;
    double pickY = y+mTY*0.5;
    double pickZ = z+mTZ*0.5;

    int cx = qCeil(pickX);
    int fx = qFloor(pickX);
    double difX = cx-fx;*/
}

void Tesselator::addVertex(double x, double y, double z)
{
    mDataBuffer[mIndex].x = x;
    mDataBuffer[mIndex].y = y;
    mDataBuffer[mIndex].z = z;

    mDataBuffer[mIndex].nx = mNX;
    mDataBuffer[mIndex].ny = mNY;
    mDataBuffer[mIndex].nz = mNZ;

    mDataBuffer[mIndex].tx = mTX;
    mDataBuffer[mIndex].ty = mTY;
    mDataBuffer[mIndex].tz = mTZ;

    mDataBuffer[mIndex].light = mTX;
}

#endif // TESSELATOR_H
