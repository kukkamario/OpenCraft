#ifndef OCGUIBUTTON_H
#define OCGUIBUTTON_H

#include <QPixmap>
#include <QRect>
#include <QPainter>

#include "ocguiobject.h"
#include "screenstate.h"

class OCGuiButton: public OCGuiObject {
    Q_OBJECT

    QPixmap *mImage;

public:
    OCGuiButton(QObject *parent = 0);
    void setTexture(QPixmap *texture);
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
