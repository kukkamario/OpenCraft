#include "gamescreenstate.h"
#include "gltexture2d.h"

GameScreenState::GameScreenState(QObject *parent)
    :ScreenState(parent)
{

}

GameScreenState::~GameScreenState()
{

}

bool GameScreenState::init(MainWindow *mainWindow)
{
    Q_UNUSED(mainWindow);
//    if (!mPainter.init())
//    {
//        qCritical("Can't initialize glPainter.");
//        return false;
//    }
    return true;
}

void GameScreenState::load()
{

}

void GameScreenState::unload()
{

}

void GameScreenState::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
}

void GameScreenState::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
}


void GameScreenState::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void GameScreenState::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void GameScreenState::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void GameScreenState::paintEvent(MainWindow *mainWindow)
{
    Q_UNUSED(mainWindow);
}

void GameScreenState::paintGL(MainWindow *mainWindow)
{
    Q_UNUSED(mainWindow); //T‰m‰ est‰‰ varoitukset...

}

void GameScreenState::windowResize(int w,int h)
{

}

void GameScreenState::mouseWheelEvent(QWheelEvent *e)
{
    Q_UNUSED(e);
}

void GameScreenState::selected()
{

}

