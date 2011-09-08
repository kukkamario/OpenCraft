#include "menuscreenstate.h"
#include <QImage>
#include "glinclude/glinclude.h"
#include "gltexture2d.h"

MenuScreenState::MenuScreenState()
    :ScreenState()
{

}

MenuScreenState::~MenuScreenState()
{

}
//tekstuurien lataus...
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
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2d(-1.0f, -1.0f);
        glVertex2d(1.0f, -1.0f);
        glVertex2d(-1.0f, 1.0f);
        glVertex2d(1.0f, 1.0f);
    glEnd();
}

void MenuScreenState::windowResize(int w,int h)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0, w, h, 0, 0, 1);
    glMatrixMode (GL_MODELVIEW);
}
