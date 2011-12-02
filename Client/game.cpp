#include "game.h"
#include "mainwindow.h"
Game::Game()
    :mMainWindow(0)
{
}

Game::~Game()
{
    //Varmuuden varalta tähänkin tarkistus
    if (mMainWindow) delete mMainWindow;
}

Game *Game::instance()
{
    static Game mGame; //Tämä on varsinainen peli. Sitä voi olla vain yksi kpl.
    return &mGame;
}

bool Game::init()
{
    if (mMainWindow == 0) //Aika turha tarkitus...
    {
        mMainWindow = new MainWindow();
        connect(mMainWindow,SIGNAL(destroyed()),this,SLOT(mainWindowDeleted()));
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
