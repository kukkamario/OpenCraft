#ifndef OCGUIBUTTON_H
#define OCGUIBUTTON_H

#include <QPixmap>
#include <QRect>

#include "ocguiobject.h"
#include "screenstate.h"

class OCGuiButton: public OCGuiObject {
    Q_OBJECT

    QPixmap mImage;
public:
    OCGuiButton(QPixmap img, QRect rect);

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
