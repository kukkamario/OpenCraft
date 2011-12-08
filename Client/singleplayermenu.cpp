#include "singleplayermenu.h"
#include "ui_singleplayermenu.h"
#include "menustack.h"
#include "game.h"
SinglePlayerMenu::SinglePlayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SinglePlayerMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_OpaquePaintEvent);

    connect(ui->MainMenuButton, SIGNAL(clicked()), this, SLOT(toMainMenu()));

}

SinglePlayerMenu::~SinglePlayerMenu()
{
    delete ui;
}

void SinglePlayerMenu::toMainMenu(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eMainMenu);
}

