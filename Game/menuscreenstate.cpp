#include "menuscreenstate.h"
#include <QImage>
#include "glinclude/glinclude.h"

MenuScreenState::MenuScreenState()
    :ScreenState()
{
    mLoaded = false;
    mAngle = 0;
}

MenuScreenState::~MenuScreenState()
{

}

void MenuScreenState::load()
{
    if (!mLoaded)
    {
        mButton.load("gfx/buttontexture.png",true);
        Q_ASSERT(!mButton.isNull());
    }
}

void MenuScreenState::unload()
{
    if (mLoaded)
        mButton.unload();
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

void drawButton(float w,float h,float angle)
{
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glBegin(GL_QUADS);
            glTexCoord2f(0,1);glVertex2f(-w*0.5,h*0.5);
            glTexCoord2f(0,0);glVertex2f(-w*0.5,-h*0.5);
            glTexCoord2f(1,0);glVertex2f(w*0.5,-h*0.5);
            glTexCoord2f(1,1);glVertex2f(w*0.5,h*0.5);
        glEnd();
    glPopMatrix();
}

void MenuScreenState::render()
{
    glLoadIdentity();
    mButton.bind();
    mAngle+= 0.1;
    glTranslatef(mWindowW*0.5,mWindowH*0.5,0);
    drawButton(mWindowW*0.8,mWindowH*0.2,mAngle);

}

void MenuScreenState::windowResize(int w,int h)
{
    glViewport(0,0,w,h);
    mWindowW = w;
    mWindowH = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,h,0,0,1);
    glMatrixMode(GL_MODELVIEW);
}

void MenuScreenState::selected()
{
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
}
