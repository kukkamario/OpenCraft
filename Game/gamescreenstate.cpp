#include "gamescreenstate.h"
#include "textures.h"

GameScreenState::GameScreenState()
    :ScreenState()
{

}

GameScreenState::~GameScreenState()
{

}

bool GameScreenState::init()
{
    if (!mPainter.init())
    {
        qCritical("Can't initialize glPainter.");
        return false;
    }
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

void GameScreenState::render()
{

}

void GameScreenState::windowResize(int w,int h)
{

}

void GameScreenState::mouseWheelEvent(int wheel,int direction)
{

}
