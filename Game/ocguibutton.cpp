#include "ocguibutton.h"

OCGuiButton::OCGuiButton(QPixmap *texture, int x, int y, int w, int h){
    if(texture != 0){mImage = *texture;}
    if(x*y!=0 || w*h!=0){mRect.setRect(x, y, w, h);}
}

void OCGuiButton::setGeometry(int x, int y, int w, int h){
    mRect.setRect(x, y, w, h);
}

void OCGuiButton::setTextrue(QPixmap texture){
    mImage = texture;
}

void OCGuiButton::paint(QPainter *p){
    p->drawPixmap(mRect.x(), mRect.y(), mRect.width(), mRect.height(), mImage);
}

void OCGuiButton::update(){
}

void OCGuiButton::mouseMoveEvent(QMouseEvent *mouseEvent)
{

}

void OCGuiButton::mousePressEvent(QMouseEvent *mouseEvent)
{

}

void OCGuiButton::mouseReleaseEvent(QMouseEvent *mouseEvent)
{

}
