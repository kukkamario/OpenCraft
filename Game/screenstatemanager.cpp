#include "screenstatemanager.h"
#include "gamescreenstate.h"
#include "menuscreenstate.h"

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
    qDeleteAll(mScreenStates);
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


bool ScreenStateManager::init(int ww, int wh)
{
    mWindowW = ww;
    mWindowH = wh;

    MenuScreenState *menustate = new MenuScreenState();
    GameScreenState *gamestate = new GameScreenState();
    mScreenStates.append(menustate);
    mScreenStates.append(gamestate);
    mActiveScreenState = menustate;


    bool failed = false;
    for (QList<ScreenState*>::iterator i = mScreenStates.begin();i != mScreenStates.end();i++)
    {
        if (!(*i)->init()) return false;
    }

    mActiveScreenState->load();
    mActiveScreenState->selected();
    mActiveScreenState->windowResize(mWindowW,mWindowH);
    return true;
}


void ScreenStateManager::keyPressEvent(unsigned char key, int mouseX, int mouseY)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->keyPressEvent(key,mouseX,mouseY);
}

void ScreenStateManager::keyReleaseEvent(unsigned char key, int mouseX, int mouseY)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->keyReleaseEvent(key,mouseX,mouseY);
}

void ScreenStateManager::specialKeyPressEvent(int key, int mouseX, int mouseY)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->specialKeyPressEvent(key,mouseX,mouseY);
}

void ScreenStateManager::specialKeyReleaseEvent(int key, int mouseX, int mouseY)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->specialKeyReleaseEvent(key,mouseX,mouseY);
}

void ScreenStateManager::mouseEvent(int button, int state, int x, int y)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->mouseEvent(button,state,x,y);
}

void ScreenStateManager::render()
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->render();
}

void ScreenStateManager::windowResize(int w,int h)
{
    Q_ASSERT(mActiveScreenState);
    mWindowW = w;
    mWindowH = h;
    mActiveScreenState->windowResize(w,h);
}

void ScreenStateManager::mouseWheelEvent(int wheel, int direction)
{
    Q_ASSERT(mActiveScreenState);
    mActiveScreenState->mouseWheelEvent(wheel,direction);
}
