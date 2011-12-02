#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/QGLWidget>
#include "menustack.h"
class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    void resizeEvent(QResizeEvent *e);

    void resizeGL(int w, int h);
    void paintGL();
    void initializeGL();
    MenuStack *mMenuStack;
};

#endif // MAINWINDOW_H
