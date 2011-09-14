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
