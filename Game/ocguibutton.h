#ifndef OCGUIBUTTON_H
#define OCGUIBUTTON_H

#include <QPixmap>
#include <QRect>
#include <QPainter>
#include <QString>
#include <QObject>
#include "ocguiobject.h"
#include "screenstate.h"

class OCGuiButton: public OCGuiObject {
    Q_OBJECT

    QPixmap *mImage;
    QPixmap *mImageDown;
    QString mTitle;
    bool mFrame;
    bool mMouseOn;

public:
    OCGuiButton(QObject *parent = 0);

    void setTexture(QPixmap *texture, QPixmap *texture2);
    void paint(QPainter *p);
    void setTitle(QString title);
    void update();

    void mousePressEvent(QMouseEvent *mouseEvent);
    void mouseReleaseEvent(QMouseEvent *mouseEvent);
    void mouseMoveEvent(QMouseEvent *mouseEvent);
    void mouseWheelEvent(QWheelEvent *){}
    void keyPressEvent(QKeyEvent *){}
    void keyReleaseEvent(QKeyEvent *){}
signals:
    void pressed();
    void askRepaint();
};

#endif // OCGUIBUTTON_H
