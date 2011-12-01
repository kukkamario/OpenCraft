#include "game.h"

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
    }
}

void Game::launch()
{
    if (mMainWindow) mMainWindow->show();
}

void Game::destroy()
{
    if (mMainWindow) delete mMainWindow;
}
