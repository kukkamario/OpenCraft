#include "menuscreenstate.h"
#include <QImage>
#include "glinclude/glinclude.h"
#include "textures.h"

MenuScreenState::MenuScreenState()
    :ScreenState()
{

}

MenuScreenState::~MenuScreenState()
{

}

void MenuScreenState::load()
{

    glTexture2D nappi("gfx/buttontexture.png");

}

void MenuScreenState::unload()
{

}


bool MenuScreenState::init()
{
    return true;
}


void MenuScreenState::keyPressEvent(unsigned char key, int mouseX, int mouseY)
{

}

void MenuScreenState::keyReleaseEvent(unsigned char key, int mouseX, int mouseY)
{

}

void MenuScreenState::specialKeyPressEvent(int key, int mouseX, int mouseY)
{

}

void MenuScreenState::specialKeyReleaseEvent(int key, int mouseX, int mouseY)
{

}

void MenuScreenState::mouseEvent(int button, int state, int x, int y)
{

}

void MenuScreenState::render()
{

}

void MenuScreenState::windowResize(int w,int h)
{

}
