#ifndef OCGUI_H
#define OCGUI_H
#include "ocguiobject.h"
#include "gamescreenstate.h"
#include <QList>
class QPainter;
class OCGui:public QObject
{
public:
    OCGui(QObject *parent = 0);
    void add(OCGuiObject *object);
    void remove(OCGuiObject *object);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseWheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void update();
    void paintEvent(QPainter *p);
public slots:
    void repaint();
signals:
    void updateWindow();
private:
    QList<OCGuiObject*> mObjects;
};

#endif // OCGUI_H
