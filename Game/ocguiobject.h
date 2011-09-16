#ifndef OCGUIOBJECT_H
#define OCGUIOBJECT_H

#include <QRect>
#include <QObject>
class QPainter;
class QMouseEvent;
class QKeyEvent;
class QWheelEvent;

class OCGuiObject: public QObject
{
public:
    OCGuiObject(QObject *parent = 0):QObject(parent),mRect(0,0,100,100),mMouseTracking(false){}
    virtual ~OCGuiObject(){}
    virtual void paint(QPainter *p) = 0;
    virtual void mousePressEvent(QMouseEvent *mouseEvent) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent) = 0;
    virtual void mouseMoveEvent(QMouseEvent *mouseEvent) = 0;
    virtual void mouseWheelEvent(QWheelEvent *event) = 0;
    virtual void keyPressEvent(QKeyEvent *event) = 0;
    virtual void keyReleaseEvent(QKeyEvent *event) = 0;

    virtual void update() = 0;
    QRect rect()const{return mRect;}
    void setGeometry(const QRect &rect){mRect = rect;}
    void setGeometry(int x,int y,int w, int h){setGeometry(QRect(x,y,w,h));}
    bool mouseTracking()const{return mMouseTracking;}
    void setMouseTracking(bool enabled){mMouseTracking = enabled;}
protected:
    QRect mRect;
    bool mMouseTracking;
};

#endif // OCGUIOBJECT_H
