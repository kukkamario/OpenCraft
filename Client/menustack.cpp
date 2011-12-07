#include "menustack.h"
#include <QWidget>
#include "mainmenuwidget.h"
#include "settingsmenu.h"
#include "multiplayermenu.h"
#include <QGraphicsProxyWidget>
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
        }
    }
}


void MenuStack::resize(int w, int h)
{
    setSceneRect(0,0,w,h);
    if (mCurrent) mCurrent->setGeometry(QRectF(0,0,w,h));
}


