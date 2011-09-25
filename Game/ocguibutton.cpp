#include "ocguibutton.h"

OCGuiButton::OCGuiButton(QObject *parent)
    :OCGuiObject(parent)
{
    mImage = 0;
}


void OCGuiButton::setTexture(QPixmap *texture){
    mImage = texture;
}

void OCGuiButton::setTitle(QString title){
    mTitle = title;
}

void OCGuiButton::paint(QPainter *p)
{
    Q_ASSERT(mImage);
    p->drawPixmap(mRect, *mImage);
    p->drawText(mRect, mTitle, QTextOption(Qt::AlignCenter));
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
