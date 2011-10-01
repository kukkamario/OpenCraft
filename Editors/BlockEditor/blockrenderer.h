#ifndef BLOCKRENDERER_H
#define BLOCKRENDERER_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include "blockvertex.h"

class BlockRenderer : public QGLWidget
{
    Q_OBJECT
public:
    explicit BlockRenderer(QWidget *parent = 0);
signals:

public slots:

private:
    BlockVertex *mVertices;
    QGLShaderProgram *mShaderProgram;
    int mVerticeCount;
};

#endif // BLOCKRENDERER_H
