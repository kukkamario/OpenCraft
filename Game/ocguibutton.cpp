#include "ocguibutton.h"
#include <QDebug>
#include <QMouseEvent>

OCGuiButton::OCGuiButton(QObject *parent)
    :OCGuiObject(parent)
{
    mImage = 0;
    mFrame = false;
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

    }else{
        QRect mMovedRect = mRect;
        mMovedRect.setX(mRect.x()+2);
        mMovedRect.setY(mRect.y()+2);
        p->drawPixmap(mRect, *mImageDown);
        p->drawText(mMovedRect, mTitle, QTextOption(Qt::AlignCenter));

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
    if (!mFrame)
    {
        //Ruutu päivitettään vain jos on tarpeellista
        mFrame = true;
        emit askRepaint();
    }
}

void OCGuiButton::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    if (mFrame)
    { //Ruutu päivitettään vain jos on tarpeellista
        mFrame = false;
        if (mRect.contains(mouseEvent->pos()))
        {
            emit pressed();
        }
        emit askRepaint();
    }
}
