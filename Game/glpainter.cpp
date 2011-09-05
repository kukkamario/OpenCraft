#include "glpainter.h"

glPainter::glPainter()
{
    mFOV = 90.0f;
    mNearPlane = 0.01f;
    mFarPlane = 1000.0f;
    mAspectRatio = 1.0f;

    mCameraPos.setZ(10);
    mCameraUpVector.setY(1);

    mDirtyProjectionMatrix = true;
}

bool glPainter::init()
{
    if (!loadExtension()) return false;
    mFOV = 90.0f;
    mNearPlane = 0.01f;
    mFarPlane = 1000.0f;
    mAspectRatio = 1.0f;

    mCameraPos.setZ(10);
    mCameraUpVector.setY(1);

    mDirtyProjectionMatrix = true;

    mMatrixStack.clear();
    return true;
}

void glPainter::beginPaint()
{
    if (mDirtyProjectionMatrix)
    {
        glMatrixMode(GL_PROJECTION);
        gluPerspective(mFOV,mAspectRatio,mNearPlane,mFarPlane);
    }
    glMatrixMode(GL_MODELVIEW);
    mMatrixStack.clear();
    QMatrix4x4 viewMatrix = QMatrix4x4();
    viewMatrix.lookAt(QVector3D(),mCameraLookAt-mCameraPos,mCameraUpVector);
    viewMatrix.translate(-mCameraPos);
    mMatrixStack.append(viewMatrix);
    mMatrixStack.append(QMatrix4x4());
    mCalcMatrixStack.append(viewMatrix);

}
