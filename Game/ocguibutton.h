#ifndef OCGUIBUTTON_H
#define OCGUIBUTTON_H

#include <QPixmap>
#include <QRect>
#include <QPainter>

#include "ocguiobject.h"
#include "screenstate.h"

class OCGuiButton: public OCGuiObject {
    Q_OBJECT

    QPixmap mImage;
    QRect mRect;

public:
    OCGuiButton(QPixmap *texture = 0, int x = 0, int y = 0, int w = 0, int h = 0);
    void setGeometry(int x, int y, int w, int h);
    void setTextrue(QPixmap texture);
    void paint(QPainter *p);

    void update();
    void mousePressEvent(QMouseEvent *mouseEvent);
    void mouseReleaseEvent(QMouseEvent *mouseEvent);
    void mouseMoveEvent(QMouseEvent *mouseEvent);
    void mouseWheelEvent(QWheelEvent *){}
    void keyPressEvent(QKeyEvent *){}
    void keyReleaseEvent(QKeyEvent *){}
signals:
    void pressed();
};

#endif // OCGUIBUTTON_H
