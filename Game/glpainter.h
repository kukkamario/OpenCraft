#ifndef GLPAINTER_H
#define GLPAINTER_H
#include "glinclude/glinclude.h"
#include <QMatrix4x4>
#include <QStack>
#include <QVector3D>

class glPainter
{
public:
    glPainter();
    bool init();

    void pushMatrix()
    {
        if (mMatrixStack.size() > 1)
        {
            mCalcMatrixStack.push(mCalcMatrixStack.last()*mMatrixStack.last());
        }
        mMatrixStack.push(QMatrix4x4());
    }
    void matrixReady()
    {
        if (mMatrixStack.size() > 1)
        {
            glLoadMatrixd((mCalcMatrixStack.last()*mMatrixStack.last()).constData());
        }
    }



    void popMatrix(){mMatrixStack.pop();mCalcMatrixStack.pop();}
    void loadMatrix(const QMatrix4x4 &mat){mMatrixStack.last() = mat;}
    QMatrix4x4 &getMatrix(){return mMatrixStack.last();}
    void setCameraPos(const QVector3D &pos);
    void moveCamera(const QVector3D &pos);
    void setCameraLookAt(const QVector3D &lookAt);
    void setCameraUpVector(const QVector3D &up);
    void setFOV(const float fov);
    void setNearPlane(const float nearP);
    void setFarPlane(const float farP);
    void setAspectRatio(const float aspect);

    void beginPaint();
    void endPaint();

private:
    QStack<QMatrix4x4> mMatrixStack;
    QStack<QMatrix4x4> mCalcMatrixStack;
    QMatrix4x4 mCurrentResult;

    QVector3D mCameraPos;
    QVector3D mCameraLookAt;
    QVector3D mCameraUpVector;

    float mFOV;
    float mNearPlane;
    float mFarPlane;
    float mAspectRatio;

    bool mDirtyProjectionMatrix;
};

#endif // GLPAINTER_H
