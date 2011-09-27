#include "ocguibutton.h"
#include <QDebug>

OCGuiButton::OCGuiButton(QObject *parent)
    :OCGuiObject(parent)
{
    mImage = 0;
}


void OCGuiButton::setTexture(QPixmap *texture, QPixmap *texture2){
    mImage = texture;
    mImageDown = texture2;
}

void OCGuiButton::setTitle(QString title){
    mTitle = title;
}

void OCGuiButton::paint(QPainter *p)
{
    Q_ASSERT(mImage);
    if(mFrame == false){
        p->drawPixmap(mRect, *mImage);
        p->drawText(mRect, mTitle, QTextOption(Qt::AlignCenter));
        askRepaint();
    }else{
        QRect mMovedRect = mRect;
        mMovedRect.setX(mRect.x()+2);
        mMovedRect.setY(mRect.y()+2);
        p->drawPixmap(mRect, *mImageDown);
        p->drawText(mMovedRect, mTitle, QTextOption(Qt::AlignCenter));
        askRepaint();
    }

}

void OCGuiButton::update()
{

}

void OCGuiButton::mouseMoveEvent(QMouseEvent *mouseEvent)
{

}

void OCGuiButton::mousePressEvent(QMouseEvent *mouseEvent)
{
    mFrame = true;
}

void OCGuiButton::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    mFrame = false;
}
