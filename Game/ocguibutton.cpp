#include "ocguibutton.h"

OCGuiButton::OCGuiButton(QObject *parent)
    :OCGuiObject(parent)
{
    mImage = 0;
}


void OCGuiButton::setTexture(QPixmap *texture){
    mImage = texture;
}

void OCGuiButton::paint(QPainter *p)
{
    Q_ASSERT(mImage);
    p->drawPixmap(mRect, *mImage);
}

void OCGuiButton::update()
{

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
