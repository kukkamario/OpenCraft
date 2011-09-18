#include "screenstatemanager.h"
#include "gamescreenstate.h"
#include "menuscreenstate.h"
#include "mainwindow.h"

ScreenStateManager *ScreenStateManager::instance()
{
    static ScreenStateManager mScreenStateManager;
    return &mScreenStateManager;
}


ScreenStateManager::ScreenStateManager()
{
    mActiveScreenState = NULL;
}

ScreenStateManager::~ScreenStateManager()
{
}

void ScreenStateManager::changeStateTo(const char *name)
{
    for (QList<ScreenState*>::iterator i = mScreenStates.begin();i != mScreenStates.end();i++)
    {
        if (stricmp(name,(*i)->name()))
        {
            mActiveScreenState->unload();
            mActiveScreenState = *i;
            mActiveScreenState->load();
            mActiveScreenState->selected();
            mActiveScreenState->windowResize(mWindowW,mWindowH);
        }
    }
}


bool ScreenStateManager::init(int ww, int wh, MainWindow *mainwindow)
{
    mWindowW = ww;
    mWindowH = wh;

    MenuScreenState *menustate = new MenuScreenState(this);
    GameScreenState *gamestate = new GameScreenState(this);
    mScreenStates.append(menustate);
    mScreenStates.append(gamestate);
    mActiveScreenState = menustate;


    bool failed = false;
    for (QList<ScreenState*>::iterator i = mScreenStates.begin();i != mScreenStates.end();i++)
    {
        if (!(*i)->init(mainwindow)) return false;
        connect(*i,SIGNAL(repaintGL()),mainwindow,SLOT(updateGL()));
    }

    mActiveScreenState->load();
    mActiveScreenState->selected();
    mActiveScreenState->windowResize(mWindowW,mWindowH);
    return true;
}


void ScreenStateManager::keyPressEvent(QKeyEvent *event)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->keyPressEvent(event);
}

void ScreenStateManager::keyReleaseEvent(QKeyEvent *event)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->keyReleaseEvent(event);
}

void ScreenStateManager::mousePressEvent(QMouseEvent *event)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->mousePressEvent(event);
}

void ScreenStateManager::mouseMoveEvent(QMouseEvent *event)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->mouseMoveEvent(event);
}

void ScreenStateManager::mouseReleaseEvent(QMouseEvent *event)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->mouseReleaseEvent(event);
}

void ScreenStateManager::paintGL(MainWindow *mainwindow)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->paintGL(mainwindow);
}

void ScreenStateManager::paintEvent(MainWindow *mainwindow)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->paintEvent(mainwindow);
}

void ScreenStateManager::windowResize(int w,int h)
{
    Q_ASSERT(mActiveScreenState);
    mWindowW = w;
    mWindowH = h;
    mActiveScreenState->windowResize(w,h);
}

void ScreenStateManager::mouseWheelEvent(QWheelEvent *e)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->mouseWheelEvent(e);
}

void ScreenStateManager::update()
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->update();
}
