#include "settingsmenu.h"
#include "ui_settingsmenu.h"
#include "menustack.h"
#include "game.h"

SettingsMenu::SettingsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_OpaquePaintEvent);
    connect(ui->BackButton, SIGNAL(clicked()), this, SLOT(toMainMenu()));
    connect(ui->ControlsButton, SIGNAL(clicked()), this, SLOT(toControlsMenu()));
}

SettingsMenu::~SettingsMenu()
{
    delete ui;
}

void SettingsMenu::toMainMenu(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eMainMenu);
}

void SettingsMenu::toControlsMenu(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eControls);
}


