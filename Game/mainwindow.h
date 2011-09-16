#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGLWidget>

class MainWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void setAutoRepaint(bool enabled);
    void setAutoRepaintTime(int ms);
private:
    void paintGL();
    void paintEvent(QPaintEvent *);
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void wheelEvent(QWheelEvent *e);

    void initializeGL();
signals:

public slots:

private:
    bool mAutoRepaintEnabled;
    QTimer *mAutoRepaintTimer;
};

#endif // MAINWINDOW_H
