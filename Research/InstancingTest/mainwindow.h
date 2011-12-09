#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/qgl.h>
#include <QtOpenGL/QGLShader>
#include <QtOpenGL/QGLShaderProgram>
#include <QtOpenGL/QGLBuffer>
#include <QMap>
#include <QLinkedList>
#include "defines.h"
#define VERTEX_POS_LOC 0
#define NORMAL_LOC 1
#define TEXTURE_COORD_LOC 2
#define LIGHT_LOC 3

#define BLOCK_TYPES 2
typedef unsigned char uchar;

#pragma pack(1)
struct VertexData
{
    float x,y,z;//0
    float tx,ty,tz;//12
    char nx,ny,nz,align;//24
    float light; //28
};

struct ChunkCoord
{
    unsigned char x,y,z;
};

struct Block
{
    int mBlockType;
};
#pragma pack()


class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    MainWindow(const QGLFormat &format,QWidget *parent = 0);
    ~MainWindow();


private:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void paintGL();
    void initializeGL();
    void resizeGL(int w, int h);

    Block mMap[MAP_SIZE*MAP_SIZE*MAP_SIZE];
    float mLighting[(MAP_SIZE+2)*(MAP_SIZE+2)*(MAP_SIZE+2)];

    QGLShaderProgram *mProgram;
    QGLShader *mVertexShader;
    QGLShader *mFragmentShader;
    GLuint mTexture;

    void floodLight(int x,int y,int z,float lightLevel);

    QTimer *mFPSTimer;
    QTimer *mRepaintTimer;
    int mFPSCounter;
    int mFPS;

    int mBlocks;

    VertexData *mVertexDataBuffer;
    int mVertexDataBufferSize;
    int mQuadCount;

    int mUniformModelViewMatrix;
    int mUniformModelViewProjectionMatrix;
    int mUniformInverseProjectionMatrix;
    int mUniformProjectionMatrix;
    int mUniformNormalMatrix;
    int mUniformTextureArray;
    int mUniformViewportSize;

    QVector3D mCameraPos;
    QVector3D mCameraRotation;

    QPointF mMouseLastPos;

    QGLBuffer mBuffer;
    float interpolateLight(double x, double y, double z,double mNX,double mNY,double mNZ);
    float mMoveZ;
    float mMoveX;
    float mMoveY;
    void createDisplayList();
private slots:
    void secondTick();

};

#endif // MAINWINDOW_H
