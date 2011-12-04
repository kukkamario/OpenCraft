#include "menustack.h"
#include <QWidget>
#include "mainmenuwidget.h"
MenuStack::MenuStack(QWidget *parent) :
    QStackedWidget(parent)
{
    memset(mMenus,0,sizeof(QWidget*)*eMenuStateCount);//Nollataan taulukko, kun se ei ole vielä täynnä, niin että voi tarkistaa onko widgetti olemassa

    //setAttribute(Qt::WA_OpaquePaintEvent);//Läpinäkyvä tausta

    mMenus[0] = new MainMenuWidget;
    this->addWidget(mMenus[0]);


    //Muut valikot vastaavasti tähän vaa..


    this->setCurrentIndex(0);
}


void MenuStack::openMenu(MenuState menu)
{
    setEnabled(true);//Varmistetaan että valikot varmasti ovat näkyvissä
    setVisible(true);
    setCurrentIndex((int)menu); //Valitaa näytettäväksi parametrina annettu
}


void MenuStack::hideMenu()
{
    //Piilotetaan valikko
    setEnabled(false);
    setVisible(true);
}
