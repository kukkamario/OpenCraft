#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"
#include "menustack.h"
#include "game.h"
MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    connect(ui->SettingsButton, SIGNAL(clicked()), this, SLOT(toOptions()));
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

void MainMenuWidget::toOptions(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eOptions);
}
