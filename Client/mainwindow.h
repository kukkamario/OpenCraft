#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/QGLWidget>
#include "menustack.h"
#include <QGraphicsView>
#include <QGraphicsProxyWidget>

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MenuStack *openMenus();
    void closeMenus();
private:

    void drawBackground(QPainter *painter, const QRectF &rect);

    void resizeEvent(QResizeEvent *e);
};

#endif // MAINWINDOW_H
