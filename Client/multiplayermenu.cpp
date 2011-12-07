#include "multiplayermenu.h"
#include "ui_multiplayermenu.h"
#include "menustack.h"
#include "game.h"

MultiPlayerMenu::MultiPlayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiPlayerMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_OpaquePaintEvent);

    connect(ui->MainMenuButton, SIGNAL(clicked()), this, SLOT(toMainMenu()));

}

MultiPlayerMenu::~MultiPlayerMenu()
{
    delete ui;
}

void MultiPlayerMenu::toMainMenu(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eMainMenu);
}

