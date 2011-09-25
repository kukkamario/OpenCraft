#include "ocgui.h"
#include <QMouseEvent>

OCGui::OCGui(QObject *parent)
    :QObject(parent)
{
}


void OCGui::add(OCGuiObject *object)
{
    object->setParent(this);
    mObjects.append(object);
}

void OCGui::remove(OCGuiObject *object)
{
    object->setParent(this);
    mObjects.removeOne(object);
}

void OCGui::mouseMoveEvent(QMouseEvent *event)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        OCGuiObject *object = *i;
        if (object->rect().contains(event->pos())) //Jos hiiri objectin päällä
        {
            if ((event->buttons() != Qt::NoButton) || object->mouseTracking())
            {
                object->mouseMoveEvent(event);
            }
        }
    }
}

void OCGui::mousePressEvent(QMouseEvent *event)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        OCGuiObject *object = *i;
        if (object->rect().contains(event->pos())) //Jos hiiri objectin päällä
        {
            object->mousePressEvent(event);
        }
    }
}

void OCGui::mouseReleaseEvent(QMouseEvent *event)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        OCGuiObject *object = *i;
        if (object->rect().contains(event->pos())) //Jos hiiri objectin päällä
        {
            object->mouseReleaseEvent(event);
        }
    }
}


void OCGui::paintEvent(QPainter *p)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        (*i)->paint(p);
    }
}

void OCGui::keyPressEvent(QKeyEvent *event)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        (*i)->keyPressEvent(event);
    }
}

void OCGui::keyReleaseEvent(QKeyEvent *event)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        (*i)->keyReleaseEvent(event);
    }
}

void OCGui::mouseWheelEvent(QWheelEvent *event)
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        OCGuiObject *object = *i;
        if (object->rect().contains(event->pos())) //Jos hiiri objectin päällä
        {
            object->mouseWheelEvent(event);
        }
    }
}

void OCGui::update()
{
    for (QList<OCGuiObject*>::iterator i = mObjects.begin();i != mObjects.end();i++)
    {
        (*i)->update();
    }
}
