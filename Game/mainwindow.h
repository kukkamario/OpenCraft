#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGLWidget>

class MainWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGL();
signals:

public slots:

};

#endif // MAINWINDOW_H
