#include "mainwindow.h"
#include "screenstatemanager.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QGLWidget(parent)
{
    mAutoRepaintEnabled = false;
    mAutoRepaintTimer = new QTimer(this);
    mAutoRepaintTimer->setInterval(10);
    connect(mAutoRepaintTimer,SIGNAL(timeout()),this,SLOT(updateGL()));

    mUpdateTimer = new QTimer(this);
    connect(mUpdateTimer,SIGNAL(timeout()),this,SLOT(updateScreenState()));

}

void MainWindow::updateScreenState()
{
    ScreenStateManager::instance()->update();
}

void MainWindow::setAutoRepaint(bool enabled)
{
    if (mAutoRepaintEnabled)
    {
        if (!enabled)
        {
            mAutoRepaintTimer->stop();
        }
    }
    else
    {
        if (enabled)
        {
            mAutoRepaintTimer->start();
        }
    }
}

void MainWindow::setAutoRepaintTime(int ms)
{
    mAutoRepaintTimer->setInterval(ms);
}

void MainWindow::paintGL()
{
    ScreenStateManager::instance()->paintGL(this);
}

void MainWindow::resizeGL(int w, int h)
{
    ScreenStateManager::instance()->windowResize(w,h);
}

void MainWindow::initializeGL()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    ScreenStateManager::instance()->paintEvent(this);
}



void MainWindow::mousePressEvent(QMouseEvent *e)
{
    ScreenStateManager::instance()->mousePressEvent(e);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    ScreenStateManager::instance()->mouseMoveEvent(e);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    ScreenStateManager::instance()->mouseReleaseEvent(e);
}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    ScreenStateManager::instance()->keyPressEvent(e);
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    ScreenStateManager::instance()->keyReleaseEvent(e);
}

void MainWindow::wheelEvent(QWheelEvent *e)
{
    ScreenStateManager::instance()->mouseWheelEvent(e);
}
