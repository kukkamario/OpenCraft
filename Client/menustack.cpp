#include "menustack.h"
#include <QWidget>
#include <QGraphicsProxyWidget>
#include "mainmenuwidget.h"
#include "settingsmenu.h"
#include "multiplayermenu.h"
#include "singleplayermenu.h"
#include "controlsettingsmenu.h"
#include "game.h"
#include "mainwindow.h"

MenuStack::MenuStack(QObject *parent) :
    QGraphicsScene(parent),
    mCurrentMenuState(eMenuStateCount), //Laitetaan sellaiseksi jota ei voi valita...
    mCurrent(0)
{

}


void MenuStack::selectMenu(MenuState menu)
{
    if (mCurrentMenuState != menu) // Varmistetaan että ei tehdä turhaa työtä
    {
        if (mCurrent != 0) //Mikäli on ennestään jokin jo valittuna
        {
            removeItem((QGraphicsItem*)mCurrent); //Poistetaan se
        }
        mCurrentMenuState = menu;


        //Tähän vaan kaikki vaihtoehdot
        switch (mCurrentMenuState)
        {
        case eMainMenu:
            mCurrent = this->addWidget(new MainMenuWidget);
            break;
        case eOptions:
            mCurrent = this->addWidget(new SettingsMenu);
            break;
        case eMultiPlayer:
            mCurrent = this->addWidget(new MultiPlayerMenu);
            break;
        case eSinglePlayer:
            mCurrent = this->addWidget(new SinglePlayerMenu);
            break;
        case eControls:
            mCurrent = this->addWidget(new ControlSettingsMenu);
            break;
        }
        if (Game::instance()->mainWindow())
        {
            QSize newSize = Game::instance()->mainWindow()->size();
            resize(newSize.width(),newSize.height());
        }
    }
}


void MenuStack::resize(int w, int h)
{

    setSceneRect(0,0,w,h);
    if (mCurrent) mCurrent->setGeometry(QRectF(0,0,w,h));
}


