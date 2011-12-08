#include "keyinputwidget.h"
#include <QPainter>
#include <QPoint>
#include <QKeyEvent>
KeyInputWidget::KeyInputWidget(QString title)
{    
    this->setWindowTitle(title);
    this->setFixedWidth(198);
    this->setFixedHeight(96);
}

void KeyInputWidget::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawText(this->rect(), Qt::AlignCenter, tr("Press any keyboard key or mouse key"));
}


void KeyInputWidget::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape){
        this->reject();
    }else if(event->key()){
        mSelectedKey = event->key();
        mKeyName = event->text();
        this->accept();
    }
}

void KeyInputWidget::mousePressEvent(QMouseEvent *event){
    if(event->button()){
        Qt::MouseButton button = event->button();
        mSelectedButton = button;
        switch(button){
            case Qt::LeftButton:
                mKeyName = tr("LMB");
            break;
            case Qt::RightButton:
                mKeyName = tr("RMB");
            break;
            case Qt::MidButton:
                mKeyName = tr("CMB");
            break;
        }
        this->accept();
    }
}

void KeyInputWidget::wheelEvent(QWheelEvent *event){
    if(event->delta()){
        if(event->delta() > 0){

        }
    }
}
