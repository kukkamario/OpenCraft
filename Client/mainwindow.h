#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/QGLWidget>

class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
