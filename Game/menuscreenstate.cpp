#include "menuscreenstate.h"
#include <QImage>
#include "glinclude/glinclude.h"
#include "mainwindow.h"

#define FBO_WIDTH 800
#define FBO_HEIGHT 600

MenuScreenState::MenuScreenState(QObject *parent)
    :ScreenState(parent)
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


bool MenuScreenState::init(MainWindow *mainWindow)
{
    Q_UNUSED(mainWindow);
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

void MenuScreenState::setupGL(int w, int h)
{
    //Tähän OpenGL:llän säätö...
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(float)w/(float)h,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
}


void MenuScreenState::paintEvent(MainWindow *mainWindow)
{
    if (mLastTime + CLOCKS_PER_SEC > clock())
    {
        mLastTime = clock();
        mFPS = mFPSCounter;
        mFPSCounter = 0;
    }

    QPainter p(mainWindow);

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glEnable(GL_MULTISAMPLE);

    setupGL(mWindowW, mWindowH);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    //Tähän kaikki opengl taustan piirto...
    gluLookAt(0,0,5,0,0,0,0,1,0);

    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);glVertex3f(1,1,0);
        glColor3f(0,1,0);glVertex3f(-1,1,0);
        glColor3f(0,0,1);glVertex3f(0,-1,0);
    glEnd();


    //---------------------------------


    glPopAttrib();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();


    p.setBackgroundMode(Qt::TransparentMode);
    p.drawText(200,200,QString("QPainter: FPS:")+QString::number(mFPS));

    p.end();
    mFPSCounter++;
}

void MenuScreenState::paintGL(MainWindow *mainWindow)
{
    //Yllätys... Eipäs laitetakkaan tähän mitään... Vaatii hieman kikkailua että saadaan
    //OpenGL:llä renderöity tausta ja QPainterilla piirretyt napit toimimaan...
    //Tässä asiasta enemmän: http://doc.qt.nokia.com/latest/opengl-overpainting.html

}

void MenuScreenState::windowResize(int w,int h)
{
    setupGL(w,h);
    mWindowW = w;
    mWindowH = h;
}

void MenuScreenState::selected()
{
    glEnable(GL_TEXTURE_2D);
    glClearColor(1,0,0,0);
}
