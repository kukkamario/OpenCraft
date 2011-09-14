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

void GameScreenState::keyPressEvent(unsigned char key, int mouseX, int mouseY)
{

}

void GameScreenState::keyReleaseEvent(unsigned char key, int mouseX, int mouseY)
{

}

void GameScreenState::specialKeyPressEvent(int key, int mouseX, int mouseY)
{

}

void GameScreenState::specialKeyReleaseEvent(int key, int mouseX, int mouseY)
{

}

void GameScreenState::mouseEvent(int button, int state, int x, int y)
{

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

void GameScreenState::mouseWheelEvent(int wheel,int direction)
{

}

void GameScreenState::selected()
{

}

