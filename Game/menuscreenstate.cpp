#include "menuscreenstate.h"
#include <QImage>
#include "glinclude/glinclude.h"


#define FBO_WIDTH 800
#define FBO_HEIGHT 600

MenuScreenState::MenuScreenState()
    :ScreenState()
{
    mLoaded = false;
    mFPS = 0;
    mFPSCounter = 0;
    mLastTime = clock();
}

MenuScreenState::~MenuScreenState()
{

}

void MenuScreenState::load()
{
    if (!mLoaded)
    {
    }
}

void MenuScreenState::unload()
{
    if (mLoaded)
    {

    }
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
    if (clock() > mLastTime + CLOCKS_PER_SEC)
    {
        mFPS = mFPSCounter;
        mFPSCounter = 0;
        mLastTime = clock();
    }
    glLoadIdentity();
    glRasterPos2i(100,100);
    glColor3f(1,1,1);
    glutBitmapString(GLUT_BITMAP_9_BY_15,(const unsigned char*)(const char*)(QByteArray("FPS:")+QByteArray::number(mFPS)));

    mFPSCounter++;
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
