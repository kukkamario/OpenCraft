#include "controlsettingsmenu.h"
#include "ui_controlsettingsmenu.h"
#include "keyinputwidget.h"
#include "menustack.h"
#include "game.h"

ControlSettingsMenu::ControlSettingsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlSettingsMenu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_OpaquePaintEvent);


    connect(ui->BackToSettings, SIGNAL(clicked()), this, SLOT(toSettingsMenu()));
    connect(ui->BackToMainMenu, SIGNAL(clicked()), this, SLOT(toMainMenu()));
    connect(ui->ForwardButton, SIGNAL(clicked()), this, SLOT(setForwardKey()));
}

ControlSettingsMenu::~ControlSettingsMenu()
{
    delete ui;
}

void ControlSettingsMenu::toSettingsMenu(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eOptions);
}

void ControlSettingsMenu::toMainMenu(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eMainMenu);
}


void ControlSettingsMenu::setForwardKey(){
    KeyInputWidget *widget;
    widget = new KeyInputWidget("Forward key");
    widget->exec();
}
