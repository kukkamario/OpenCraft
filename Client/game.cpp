#include "game.h"
#include "mainwindow.h"
#include "menustack.h"
#include "inputsystem.h"

static Game *mInstance = 0;

Game::Game(int argc, char *argv[]):
    QApplication(argc,argv),
    mMainWindow(0),
    mInputSystem(0)
{
    if (mInstance) {qFatal("WHAAAAAAT????!!!!");exit(-1);}
    mInstance = this;
}

Game::~Game()
{
    //Varmuuden varalta tähänkin tarkistus
    if (mMainWindow) delete mMainWindow;
}

bool Game::init()
{
    if (mMainWindow == 0) //Aika turha tarkitus...
    {
        mMainWindow = new MainWindow;
        connect(mMainWindow,SIGNAL(destroyed()),this,SLOT(mainWindowDeleted()));

        mInputSystem = new InputSystem(this);
    }
    return 1;
}

void Game::launch()
{
    if (mMainWindow) mMainWindow->show();
}

void Game::destroy()
{
    if (mMainWindow) delete mMainWindow;
}

void Game::mainWindowDeleted()
{
    mMainWindow = 0;
}

MenuStack *Game::openMenus()
{
    return mMainWindow->openMenus();
}

void Game::closeMenus()
{
    mMainWindow->closeMenus();
}

Game *Game::instance()
{
    return mInstance;
}
