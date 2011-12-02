#include "mainwindow.h"
#include <QResizeEvent>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QGLWidget(parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    //mMenuStack = new MenuStack(this);

}

MainWindow::~MainWindow()
{

}



void MainWindow::resizeEvent(QResizeEvent *e)
{
    mMenuStack->setGeometry(QRect(QPoint(),e->size()));
}


void MainWindow::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MainWindow::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f,0,0,0);
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
