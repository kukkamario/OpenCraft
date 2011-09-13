#include "mainwindow.h"
#include "screenstatemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QGLWidget(parent)
{
}

void MainWindow::paintGL()
{
    ScreenStateManager::instance()->render();
}

void MainWindow::resizeGL(int w, int h)
{
    ScreenStateManager::instance()->windowResize(w,h);
}

void MainWindow::initializeGL()
{

}
