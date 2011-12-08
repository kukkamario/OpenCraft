#include "mainwindow.h"
#include <GL/GLU.h>
#include <QDebug>
#include <GL/gl.h>
#include <GL/glext.h>
#include <QVector3D>
#include <QTimer>
#include <QMouseEvent>
#include <qmath.h>
#include "noise.h"

PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstanced;
PFNGLBINDFRAGDATALOCATIONEXTPROC glBindFragDataLocation;
PFNGLTEXIMAGE3DPROC glTexImage3D;
PFNGLACTIVETEXTUREPROC glActiveTexture;

#define BLOCK_AIR 0
#define BLOCK_GRASS 1
#define BLOCK_ROCK 2

#define SUN_LIGHT 1.0f
#define LIGHT_DARKENING 0.80f
#define MIN_LIGHT 0.01f

#define EYE_SEPARATION 0.006

#define FOV 70.0


QQuaternion fromEuler(double heading, double attitude, double bank)
{
    // Assuming the angles are in radians.
    double c1 = qCos(heading/2);
    double s1 = qSin(heading/2);
    double c2 = qCos(attitude/2);
    double s2 = qSin(attitude/2);
    double c3 = qCos(bank/2);
    double s3 = qSin(bank/2);
    double c1c2 = c1*c2;
    double s1s2 = s1*s2;
    return QQuaternion (c1c2*c3 - s1s2*s3,c1c2*s3 + s1s2*c3,s1*c2*c3 + c1*s2*s3,c1*s2*c3 - s1*c2*s3);
}

double vecdist(double x,double y,double z)
{
    return qSqrt(x*x+y*y+z*z);
}

void generateBlock(float* block, int top_frame, int bottom_frame, int side_frame, float cutOff = 0.05f);

MainWindow::MainWindow(const QGLFormat &format, QWidget *parent)
    : QGLWidget(format,parent),
      mProgram(0),
      mVertexShader(0),
      mFragmentShader(0),
      mBlocks(0),
      mCameraPos(30,20,100),
      mCameraRotation(0,180,0),
      mMoveX(0),
      mMoveY(0),
      mMoveZ(0),
      mVertexDataBuffer(0),
      mVertexDataBufferSize(0),
      mBuffer(QGLBuffer::VertexBuffer)
{
    mFPSTimer = new QTimer(this);
    connect(mFPSTimer,SIGNAL(timeout()),this,SLOT(secondTick()));
    mFPSTimer->start(1000);

    mRepaintTimer = new QTimer(this);
    connect(mRepaintTimer,SIGNAL(timeout()),this,SLOT(repaint()));
    mRepaintTimer->start(0);

    memset(mMap,0,MAP_SIZE*MAP_SIZE*MAP_SIZE*sizeof(Block));

    srand(13123);
    int index(0);
    double caves, center_falloff, plateau_falloff, density;
    for (int z = 0; z != MAP_SIZE;++z)
    {
        double zf = (double)z/double(MAP_SIZE);
        for (int y = 0;y != MAP_SIZE;++y)
        {
            double yf = (double)y/double(MAP_SIZE);
            for (int x = 0;x != MAP_SIZE;++x)
            {
                double xf = (double)x/double(MAP_SIZE);

                if(yf <= 0.8){
                    plateau_falloff = 1.0;
                }
                else if(0.8 < yf && yf < 0.9){
                    plateau_falloff = 1.0-(yf-0.8)*10.0;
                }
                else{
                    plateau_falloff = 0.0;
                }

                center_falloff = 0.1/(
                    qPow((xf-0.5)*1.5, 2) +
                    qPow((yf-1.0)*0.8, 2) +
                    qPow((zf-0.5)*1.5, 2)
                );
                caves = qPow(simplex_noise(1, xf*5, yf*5, zf*5), 3);
                density = (
                    simplex_noise(5, xf, yf*0.5, zf) *
                    center_falloff *
                    plateau_falloff
                );
                density *= qPow(
                    noise((xf+1)*3.0, (yf+1)*3.0, (zf+1)*3.0)+0.4, 1.8
                );
                if(caves<0.5){
                    density = 0;
                }
                if (density>3.1)
                {
                    mMap[index].mBlockType = BLOCK_ROCK;
                    ++mBlocks;
                }
                else
                {
                    mMap[index].mBlockType = BLOCK_AIR;
                }
                ++index;
            }
        }
    }


    for (int i = 0; i != (MAP_SIZE+2)*(MAP_SIZE+2)*(MAP_SIZE+2);++i)
                mLighting[i] =0;

    /*
          index = 0;
    for (int z = 0; z != MAP_SIZE;++z)
        for (int y = 0;y != MAP_SIZE-1;++y)
            for (int x = 0;x != MAP_SIZE;++x)
            {
                if (mMap[index].mBlockType == BLOCK_ROCK)
                {
                    if (mMap[index+MAP_SIZE].mBlockType == BLOCK_AIR)
                    {
                        mMap[index].mBlockType = BLOCK_GRASS;
                    }
                }
                ++index;
            }*/
    mBlocks = index;







    qDebug() << "OpenGL:"<<this->format().majorVersion()<<"."<<this->format().minorVersion();
}

MainWindow::~MainWindow()
{
    this->deleteTexture(mTexture);
}

void MainWindow::initializeGL()
{
    glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)this->context()->getProcAddress("glMultiTexCoord3fv");
    glBindBuffer = (PFNGLBINDBUFFERPROC)this->context()->getProcAddress("glBindBuffer");
    glVertexAttribPointer =(PFNGLVERTEXATTRIBPOINTERPROC)this->context()->getProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray =(PFNGLENABLEVERTEXATTRIBARRAYPROC)this->context()->getProcAddress("glEnableVertexAttribArray");
    glGenBuffers = (PFNGLGENBUFFERSPROC)this->context()->getProcAddress("glGenBuffers");
    glBufferData = (PFNGLBUFFERDATAPROC)this->context()->getProcAddress("glBufferData");
    glDeleteBuffers =(PFNGLDELETEBUFFERSPROC)this->context()->getProcAddress("glDeleteBuffers");
    glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)this->context()->getProcAddress("glDrawArraysInstancedEXT");
    glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONEXTPROC)this->context()->getProcAddress("glBindFragDataLocationEXT");
    glTexImage3D = (PFNGLTEXIMAGE3DPROC)this->context()->getProcAddress("glTexImage3D");
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)this->context()->getProcAddress("glActiveTexture");
    if (!(glEnableVertexAttribArray && glMultiTexCoord3fv && glBindBuffer && glVertexAttribPointer && glDrawArraysInstanced))
    {
        qCritical("GetProgAddress failed.");
        close();
        return;
    }

    mBuffer.create();

    GLenum error = glGetError();
    if (error)
    {

        qCritical() << "Init: "<< error << " :" << (const char*)gluErrorString(error);
    }


    glClearColor(0.3,0.3,0.3,0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_ALPHA_TEST);

    glEnable(GL_TEXTURE_2D);
    QPixmap tex(":/texture.png");
    if (tex.isNull())
    {
        qCritical("Can't load texture");
    }
    mTexture = this->bindTexture(tex);

    error = glGetError();
    if (error)
    {

        qCritical() << "Texture array: "<< error << " :" << (const char*)gluErrorString(error);
    }


    mVertexShader = new QGLShader(QGLShader::Vertex,this);
    if (!mVertexShader->compileSourceFile(":/vertex.vert"))
    {
        qCritical("Can't compile vertex shader.\n");
        qCritical() << mVertexShader->log();
        delete mVertexShader;
        mVertexShader = 0;
        close();
        return;
    }
    qDebug("Vertex shader compiled.");

    mFragmentShader = new QGLShader(QGLShader::Fragment,this);
    if (!mFragmentShader->compileSourceFile(":/fragment.frag"))
    {
        qCritical("Can't compile fragment shader.\n");
        qCritical() << mFragmentShader->log();
        delete mFragmentShader;
        mFragmentShader = 0;
        close();
        return;
    }
    qDebug("Fragment shader compiled.");

    mProgram = new QGLShaderProgram(this);
    mProgram->addShader(mVertexShader);
    mProgram->addShader(mFragmentShader);

    mProgram->bindAttributeLocation("vertex",VERTEX_POS_LOC);
    mProgram->bindAttributeLocation("normal",NORMAL_LOC);
    mProgram->bindAttributeLocation("texCoordIn",TEXTURE_COORD_LOC);
    mProgram->bindAttributeLocation("light",LIGHT_LOC);

    glBindFragDataLocation(mProgram->programId(),0,"fragColor");

    if (!mProgram->link())
    {
        qCritical("Can't link shaderprogram.\n");
        qCritical() << mProgram->log();
        delete mProgram;
        mProgram = 0;
        close();
        return;
    }
    qDebug("Shaderprogram linked.");

    mUniformModelViewMatrix = mProgram->uniformLocation("modelViewMatrix");
    mUniformModelViewProjectionMatrix = mProgram->uniformLocation("modelViewProjectionMatrix");
    mUniformProjectionMatrix = mProgram->uniformLocation("projectionMatrix");
    mUniformNormalMatrix = mProgram->uniformLocation("normalMatrix");
    mUniformTextureArray = mProgram->uniformLocation("textureArray");
    mUniformInverseProjectionMatrix = mProgram->uniformLocation("inverseProjectionMatrix");
    mUniformViewportSize = mProgram->uniformLocation("viewportSize");

    error = glGetError();
    if (error)
    {

        qCritical() << "Shaders: "<< error << " :" << (const char*)gluErrorString(error);
    }

    qDebug("Calculating lighting");
    char buffer[MAP_SIZE*MAP_SIZE];
    memset(buffer,1,(MAP_SIZE)*(MAP_SIZE));
    for (int y = MAP_SIZE-1;y != -1;--y)
        for (int z = 0; z != MAP_SIZE;++z)
            for (int x = 0;x != MAP_SIZE;++x)
            {
                if (buffer[x + z*MAP_SIZE]== 1)
                {
                    if (mMap[x + y*MAP_SIZE + z*MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
                    {
                        floodLight(x,y,z,SUN_LIGHT);
                    }
                    else
                    {
                        buffer[x + z*MAP_SIZE] = 0;
                    }

                }
            }

    qDebug("Lighting calculated");

    createDisplayList();
}

void MainWindow::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MainWindow::paintGL()
{
    ++mFPSCounter;
    if (mProgram && mFragmentShader && mVertexShader)
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        QMatrix4x4 projection;
        projection.perspective(70,(double)this->width()/(double)this->height(),0.1,1000);
        glLoadMatrixd(projection.data());

        glMatrixMode(GL_MODELVIEW);
        QMatrix4x4 modelViewMatrix;
        modelViewMatrix.rotate(mCameraRotation.x(),1,0,0);
        modelViewMatrix.rotate(mCameraRotation.y(),0,1,0);
        modelViewMatrix.rotate(mCameraRotation.z(),0,0,1);
        mCameraPos += QVector3D(mMoveX,mMoveY,mMoveZ)*modelViewMatrix;
        modelViewMatrix.setToIdentity();
        modelViewMatrix.lookAt(QVector3D(),QVector3D(0,0,10),QVector3D(0,1,0));
        modelViewMatrix.rotate(mCameraRotation.x(),1,0,0);
        modelViewMatrix.rotate(mCameraRotation.y(),0,1,0);
        modelViewMatrix.rotate(mCameraRotation.z(),0,0,1);
        modelViewMatrix.translate(-mCameraPos);
        glLoadMatrixd(modelViewMatrix.data());

        glActiveTexture(GL_TEXTURE0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,mTexture);




        GLenum error = glGetError();
        if (error)
        {

            qCritical() << "Bind texture: "<< error << " :" << (const char*)gluErrorString(error);
        }


        mProgram->bind();
        error = glGetError();
        if (error)
        {

            qCritical() << "Program bind: "<< error << " :" << (const char*)gluErrorString(error);
        }

        mProgram->enableAttributeArray(VERTEX_POS_LOC);
        mProgram->enableAttributeArray(NORMAL_LOC);
        mProgram->enableAttributeArray(TEXTURE_COORD_LOC);
        mProgram->enableAttributeArray(LIGHT_LOC);
        mBuffer.bind();
        mProgram->setAttributeBuffer(VERTEX_POS_LOC,GL_FLOAT,0,3,32);
        mProgram->setAttributeBuffer(TEXTURE_COORD_LOC,GL_FLOAT,12,3,32);
        mProgram->setAttributeBuffer(NORMAL_LOC,GL_BYTE,24,3,32);
        mProgram->setAttributeBuffer(LIGHT_LOC,GL_FLOAT,28,1,32);


        if (mUniformModelViewMatrix != -1) mProgram->setUniformValue(mUniformModelViewMatrix,modelViewMatrix);

        error = glGetError();
        if (error)
        {
            qCritical() << "Program init1: "<< error << " :" << (const char*)gluErrorString(error) << "\n"<<mProgram->log();
        }


        if (mUniformProjectionMatrix != -1)
        {
            mProgram->setUniformValue(mUniformProjectionMatrix,projection);
        }

        if (mUniformInverseProjectionMatrix != -1)
        {
            mProgram->setUniformValue(mUniformInverseProjectionMatrix,projection.inverted());
        }

        if (mUniformViewportSize != -1)
        {
            mProgram->setUniformValue(mUniformViewportSize,QVector2D(width(),height()));
        }

        mProgram->setUniformValue(mUniformTextureArray,0);
        error = glGetError();
        if (error)
        {
            qCritical() << "Program init2: "<< error << " :" << (const char*)gluErrorString(error) << "\n"<<mProgram->log();
        }

        if (mUniformModelViewProjectionMatrix != -1)
        {
            QMatrix4x4 modelViewProjection = projection*modelViewMatrix;
            mProgram->setUniformValue(mUniformModelViewProjectionMatrix,modelViewProjection);

            error = glGetError();
            if (error)
            {
                qCritical() << "Program init3: "<< error << " :" << (const char*)gluErrorString(error) << "\n"<<mProgram->log();
            }
        }
        if (mUniformNormalMatrix != -1) mProgram->setUniformValue(mUniformNormalMatrix,modelViewMatrix.normalMatrix());


        error = glGetError();
        if (error)
        {
            qCritical() << "Program init4: "<< error << " :" << (const char*)gluErrorString(error) << "\n"<<mProgram->log();
        }


        glDrawArrays(GL_QUADS,0,mQuadCount*4);

        error = glGetError();
        if (error)
        {

            qCritical() << "End: "<< error << " :" << (const char*)gluErrorString(error);
        }


    }
}

void MainWindow::secondTick()
{
    mFPS = mFPSCounter;
    this->setWindowTitle("Blocks:" +QString::number(mBlocks)+ "  FPS:"+QString::number(mFPS));
    mFPSCounter = 0;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    mMouseLastPos = e->posF();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mCameraRotation += QVector3D((e->posF().y()-mMouseLastPos.y())*0.08,(mMouseLastPos.x()-e->posF().x())*0.08,0);

    mMouseLastPos = e->posF();
}

#define MOVE 0.14f
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Up){mMoveZ += MOVE;return;}
    if (e->key() == Qt::Key_Down){mMoveZ -= MOVE;return;}
    if (e->key() == Qt::Key_Left){mMoveX += MOVE;return;}
    if (e->key() == Qt::Key_Right){mMoveX -= MOVE;return;}
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Up){mMoveZ -= MOVE;return;}
    if (e->key() == Qt::Key_Down){mMoveZ += MOVE;return;}
    if (e->key() == Qt::Key_Left){mMoveX -= MOVE;return;}
    if (e->key() == Qt::Key_Right){mMoveX += MOVE;return;}
}


float getFrTexCoordX(int frame, int imgW = 1024, int fw = 64),
      getFrTexCoordY(int frame, int imgH = 1024, int fh = 64);





float getFrTexCoordX(int frame, int imgW, int fw){
      int framesRowX = imgW/fw;
      int frameX = (frame%framesRowX);
      double multip = fw/(double)imgW;
      return (double)frameX*multip;
}

float getFrTexCoordY(int frame, int imgH, int fh){
      int framesRowY = imgH/fh;
      int frameY = (frame/framesRowY);
      double multip = fh/(double)imgH;
      return 1.0-((double)frameY*multip);
}


void generateBlock(float* block, int top_frame, int bottom_frame, int side_frame, float cutOff){
   float newblock[] = {
        //Bottom face
        //x,   y,   z
        -0.5f,-0.5f,-0.5f,  0.0f,-1.0f,0.0f,    getFrTexCoordX(bottom_frame)+cutOff,getFrTexCoordY(bottom_frame)-cutOff,
        0.5f,-0.5f,-0.5f,   0.0f,-1.0f,0.0f,    getFrTexCoordX(bottom_frame)+0.05f-cutOff,getFrTexCoordY(bottom_frame)-cutOff,
        0.5f,-0.5f,0.5f,    0.0f,-1.0f,0.0f,    getFrTexCoordX(bottom_frame)+0.05f-cutOff,getFrTexCoordY(bottom_frame)-0.05f+cutOff,
        -0.5f,-0.5f,0.5f,   0.0f,-1.0f,0.0f,    getFrTexCoordX(bottom_frame)+cutOff,getFrTexCoordY(bottom_frame)-0.05f+cutOff,

        //Front face
        //x,   y,   z
        -0.5f,-0.5f,0.5f,   0.0f,0.0f,1.0f,     getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        0.5f,-0.5f,0.5f,    0.0f,0.0f,1.0f,     getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        0.5f,0.5f,0.5f,     0.0f,0.0f,1.0f,     getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-cutOff,
        -0.5f,0.5f,0.5f,    0.0f,0.0f,1.0f,     getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-cutOff,

        // Back Face
        //x,   y,   z
        -0.5f,-0.5f,-0.5f,  0.0f,0.0f,-1.0f,    getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        0.5f,-0.5f,-0.5f,   0.0f,0.0f,-1.0f,    getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        0.5f,0.5f,-0.5f,    0.0f,0.0f,-1.0f,    getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-cutOff,
        -0.5f,0.5f,-0.5f,   0.0f,0.0f,-1.0f,    getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-cutOff,

        // Right face
        //x,   y,   z
        0.5f,-0.5f,-0.5f,   1.0f,0.0f,0.0f,     getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        0.5f,-0.5f,0.5f,    1.0f,0.0f,0.0f,     getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        0.5f,0.5f,0.5f,     1.0f,0.0f,0.0f,     getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-cutOff,
        0.5f,0.5f,-0.5f,    1.0f,0.0f,0.0f,     getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-cutOff,

        // Left face
        //x,   y,   z
        -0.5f,-0.5f,-0.5f,  -1.0f,0.0f,0.0f,    getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        -0.5f,-0.5f,0.5f,   -1.0f,0.0f,0.0f,    getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-0.05f+cutOff,
        -0.5f,0.5f,0.5f,    -1.0f,0.0f,0.0f,    getFrTexCoordX(side_frame)+0.05f-cutOff,getFrTexCoordY(side_frame)-cutOff,
        -0.5f,0.5f,-0.5f,   -1.0f,0.0f,0.0f,    getFrTexCoordX(side_frame)+cutOff,getFrTexCoordY(side_frame)-cutOff,

        //Top face
        //x,   y,   z
        -0.5f,0.5f,-0.5f,   0.0f,1.0f,0.0f,     getFrTexCoordX(top_frame)+cutOff,getFrTexCoordY(top_frame)-cutOff,
        0.5f,0.5f,-0.5f,    0.0f,1.0f,0.0f,     getFrTexCoordX(top_frame)+0.05f-cutOff,getFrTexCoordY(top_frame)-cutOff,
        0.5f,0.5f,0.5f,   0.0f,1.0f,0.0f,     getFrTexCoordX(top_frame)+0.05f-cutOff,getFrTexCoordY(top_frame)-0.05f+cutOff,
        -0.5f,0.5f,0.5f,    0.0f,1.0f,0.0f,     getFrTexCoordX(top_frame)+cutOff,getFrTexCoordY(top_frame)-0.05f+cutOff
    };
    memcpy(block, newblock, 24*8*4);

}

struct LightState
{
    LightState(uchar px,uchar py, uchar pz,float light):x(px),y(py),z(pz),lightLevel(light){}
    unsigned char x,y,z;
    float lightLevel;

};



//TODO: TEE TÄMÄ
void MainWindow::floodLight(int x, int y,int z, float lightLevel)
{
    ++x;++y;++z;
    if (mLighting[x + y *(MAP_SIZE+2) + z *(MAP_SIZE+2)*(MAP_SIZE+2)] > lightLevel)
    {
        qDebug("WAAAT!");
        return;
    }
    mLighting[x + y *(MAP_SIZE+2) + z *(MAP_SIZE+2)*(MAP_SIZE+2)] = lightLevel;
    //return;
    QLinkedList<LightState> mStack;
    mStack.clear();
    mStack.append(LightState(x,y,z,lightLevel));
    float ls;
    float newLs;

    while (!mStack.isEmpty())
    {
        const LightState current = mStack.takeFirst();

        newLs = current.lightLevel* LIGHT_DARKENING;
        if (newLs < MIN_LIGHT)
        {
            continue;
        }
        if (current.x != 1)
        {
            if (mMap[(current.x-1)-1 + (current.y-1) *MAP_SIZE + (current.z-1) *MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
            {
                ls = mLighting[current.x-1 + current.y *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)];
                if (ls < newLs)
                {
                    mStack.push_front(LightState(current.x-1,current.y,current.z,newLs));
                    mLighting[current.x-1 + current.y *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)] = newLs;
                }
            }
        }
        if (current.x != MAP_SIZE+1)
        {
            if (mMap[(current.x-1)+1 + (current.y-1) *MAP_SIZE + (current.z-1) *MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
            {
                ls = mLighting[current.x+1 + current.y *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)];
                if (ls < newLs)
                {
                    mStack.push_front(LightState(current.x+1,current.y,current.z,newLs));
                    mLighting[current.x+1 + current.y *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)] = newLs;
                }
            }
        }
        if (current.y != 1)
        {
            if (mMap[(current.x-1) + ((current.y-1)-1) *MAP_SIZE + (current.z-1) *MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
            {
                ls = mLighting[current.x + (current.y-1) *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)];
                if (ls < newLs)
                {
                    mStack.push_front(LightState(current.x,current.y-1,current.z,newLs));
                    mLighting[current.x + (current.y-1) *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)] = newLs;
                }
            }
        }

        if (current.y != MAP_SIZE+1)
        {
            if (mMap[(current.x-1) + ((current.y-1)+1) *MAP_SIZE + (current.z-1) *MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
            {
                ls = mLighting[current.x + (current.y+1) *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)];
                if (ls < newLs)
                {
                    mStack.push_front(LightState(current.x,current.y+1,current.z,newLs));
                    mLighting[current.x + (current.y+1) *(MAP_SIZE+2) + current.z *(MAP_SIZE+2)*(MAP_SIZE+2)] = newLs;
                }
            }
        }

        if (current.z != 1)
        {
            if (mMap[(current.x-1) + (current.y-1) *MAP_SIZE + ((current.z-1)-1) *MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
            {
                ls = mLighting[current.x + current.y *(MAP_SIZE+2) + (current.z-1) *(MAP_SIZE+2)*(MAP_SIZE+2)];
                if (ls < newLs)
                {
                    mStack.push_front(LightState(current.x,current.y,current.z-1,newLs));
                    mLighting[current.x + current.y *(MAP_SIZE+2) + (current.z-1) *(MAP_SIZE+2)*(MAP_SIZE+2)] = newLs;
                }
            }
        }
        if (current.z != MAP_SIZE+1)
        {
            if (mMap[(current.x-1) + (current.y-1) *MAP_SIZE + ((current.z-1)+1) *MAP_SIZE*MAP_SIZE].mBlockType == BLOCK_AIR)
            {
                ls = mLighting[current.x + current.y *(MAP_SIZE+2) + (current.z+1) *(MAP_SIZE+2)*(MAP_SIZE+2)];
                if (ls < newLs)
                {
                    mStack.push_front(LightState(current.x,current.y,current.z+1,newLs));
                    mLighting[current.x + current.y *(MAP_SIZE+2) + (current.z+1) *(MAP_SIZE+2)*(MAP_SIZE+2)] = newLs;
                }
            }
        }
    }
}


void MainWindow::createDisplayList()
{
    qDebug("Creating buffers");
    if (mVertexDataBuffer == 0)
    {
        mVertexDataBufferSize = 4*100;
        mVertexDataBuffer = (VertexData*)malloc(mVertexDataBufferSize*sizeof(VertexData));
    }
    int index = 0;
    mQuadCount = 0;
    mBuffer.setUsagePattern(QGLBuffer::StreamDraw);
    for (int z = 0; z != MAP_SIZE;++z)
        for (int y = 0;y != MAP_SIZE;++y)
            for (int x = 0;x != MAP_SIZE;++x)
            {
                int blockType = mMap[x + y *MAP_SIZE + z *MAP_SIZE*MAP_SIZE].mBlockType;
                if (blockType != BLOCK_AIR)
                {
                    bool draw = true;
                    if (x != 0)
                    {
                        if (mMap[x-1 + y *MAP_SIZE + z *MAP_SIZE*MAP_SIZE].mBlockType != BLOCK_AIR)
                        {
                            draw = false;
                        }
                    }
                    if (draw)
                    {
                        switch (blockType)
                        {
                        case BLOCK_ROCK:
                            if (index + 4 >= mVertexDataBufferSize)
                            {
                                mVertexDataBufferSize *= 2;
                                mVertexDataBuffer = (VertexData*)realloc(mVertexDataBuffer,mVertexDataBufferSize*sizeof(VertexData));
                            }
                            mVertexDataBuffer[index].x = -0.5 + (double)x;
                            mVertexDataBuffer[index].y = 0.5 + (double)y;
                            mVertexDataBuffer[index].z = -0.5 + (double)z;
                            mVertexDataBuffer[index].tx = 0;
                            mVertexDataBuffer[index].ty = 1;
                            mVertexDataBuffer[index].tz = 0;
                            mVertexDataBuffer[index].nx = -127;
                            mVertexDataBuffer[index].ny = 0;
                            mVertexDataBuffer[index].nz = 0;

                            index++;
                            mVertexDataBuffer[index].x = -0.5 + (double)x;
                            mVertexDataBuffer[index].y = 0.5 + (double)y;
                            mVertexDataBuffer[index].z = 0.5 + (double)z;
                            mVertexDataBuffer[index].tx = 0.5;
                            mVertexDataBuffer[index].ty = 1;
                            mVertexDataBuffer[index].tz = 0;
                            mVertexDataBuffer[index].nx = -127;
                            mVertexDataBuffer[index].ny = 0;
                            mVertexDataBuffer[index].nz = 0;

                            index++;
                            mVertexDataBuffer[index].x = -0.5 + (double)x;
                            mVertexDataBuffer[index].y = -0.5 + (double)y;
                            mVertexDataBuffer[index].z = 0.5 + (double)z;
                            mVertexDataBuffer[index].tx = 0.5;
                            mVertexDataBuffer[index].ty = 0.5;
                            mVertexDataBuffer[index].tz = 0;
                            mVertexDataBuffer[index].nx = -127;
                            mVertexDataBuffer[index].ny = 0;
                            mVertexDataBuffer[index].nz = 0;

                            index++;
                            mVertexDataBuffer[index].x = -0.5 + (double)x;
                            mVertexDataBuffer[index].y = -0.5 + (double)y;
                            mVertexDataBuffer[index].z = -0.5 + (double)z;
                            mVertexDataBuffer[index].tx = 0;
                            mVertexDataBuffer[index].ty = 0.5;
                            mVertexDataBuffer[index].tz = 0;
                            mVertexDataBuffer[index].nx = -127;
                            mVertexDataBuffer[index].ny = 0;
                            mVertexDataBuffer[index].nz = 0;
                            index++;
                            mQuadCount++;
                            break;
                        }
                    }
                    /*
                    //////////////////////////////////////////////////////
                    //Etusivu
                    //////////////////////////////////////////////////////
                    //Vasen ylänurkka
                    mVertexDataBuffer[index].x = -0.5 + (double)x;
                    mVertexDataBuffer[index].y = 0.5 + (double)y;
                    mVertexDataBuffer[index].z =  0.5 + (double)z;
                    mVertexDataBuffer[index].tx = 0;
                    mVertexDataBuffer[index].ty = 1;
                    mVertexDataBuffer[index].tz = 0;
                    mVertexDataBuffer[index].nx = -127;
                    mVertexDataBuffer[index].ny = 0;
                    mVertexDataBuffer[index].nz = 0;

                    //Oikea ylänurkka
                    index++;
                    mVertexDataBuffer[index].x =  0.5 + (double)x;
                    mVertexDataBuffer[index].y = -0.5 + (double)y;
                    mVertexDataBuffer[index].z =  0.5 + (double)z;
                    mVertexDataBuffer[index].tx = 0.5;
                    mVertexDataBuffer[index].ty = 1;
                    mVertexDataBuffer[index].tz = 0;
                    mVertexDataBuffer[index].nx = -127;
                    mVertexDataBuffer[index].ny = 0;
                    mVertexDataBuffer[index].nz = 0;

                    //Vasen alanurkka
                    index++;
                    mVertexDataBuffer[index].x = -0.5 + (double)x;
                    mVertexDataBuffer[index].y =  0.5 + (double)y;
                    mVertexDataBuffer[index].z =  0.5 + (double)z;
                    mVertexDataBuffer[index].tx = 0.5;
                    mVertexDataBuffer[index].ty = 0.5;
                    mVertexDataBuffer[index].tz = 0;
                    mVertexDataBuffer[index].nx = -127;
                    mVertexDataBuffer[index].ny = 0;
                    mVertexDataBuffer[index].nz = 0;
                    //Oikea alanurkka
                    index++;
                    mVertexDataBuffer[index].x =  0.5 + (double)x;
                    mVertexDataBuffer[index].y =  0.5 + (double)y;
                    mVertexDataBuffer[index].z =  0.5 + (double)z;
                    mVertexDataBuffer[index].tx = 0;
                    mVertexDataBuffer[index].ty = 0.5;
                    mVertexDataBuffer[index].tz = 0;
                    mVertexDataBuffer[index].nx = -127;
                    mVertexDataBuffer[index].ny = 0;
                    mVertexDataBuffer[index].nz = 0;
                    index++;*/

                }
            }

    for (int i = 0; i < index;i++)
    {
        mVertexDataBuffer[i].light = interpolateLight(mVertexDataBuffer[i].x,mVertexDataBuffer[i].y,mVertexDataBuffer[i].z,
                                                          (double)mVertexDataBuffer[i].nx/127.0,(double)mVertexDataBuffer[i].ny/127.0,(double)mVertexDataBuffer[i].nz/127.0);
    }
    mBuffer.bind();
    mBuffer.allocate(mVertexDataBuffer,sizeof(VertexData)*index);
    qDebug("Buffers created");

    GLenum error = glGetError();
    if (error)
    {

        qCritical() << "Buffers: "<< error << " :" << (const char*)gluErrorString(error);
    }
}

int minVal(int a,int b)
{
    if (a < b) return a;
    return b;
}
int maxVal(int a,int b)
{
    if (a > b) return a;
    return b;
}

float MainWindow::interpolateLight(double x, double y, double z,double mNX,double mNY,double mNZ)
{
    int pickX = x+mNX*0.5;
    int pickY = y+mNY*0.5;
    int pickZ = z+mNZ*0.5;
    pickX = minVal(maxVal(0,pickX),MAP_SIZE+1);
    pickX = minVal(maxVal(0,pickX),MAP_SIZE+1);
    pickX = minVal(maxVal(0,pickX),MAP_SIZE+1);

    return mLighting[pickX + pickY *(MAP_SIZE+2) + pickZ * (MAP_SIZE+2)*(MAP_SIZE+2)];
    /*
    double pickX = x+mTX*0.5;
    double pickY = y+mTY*0.5;
    double pickZ = z+mTZ*0.5;

    int cx = qCeil(pickX);
    int fx = qFloor(pickX);
    double difX = cx-fx;*/
}
