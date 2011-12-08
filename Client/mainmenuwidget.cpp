#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"
#include "menustack.h"
#include "game.h"
#include <QMessageBox>

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    connect(ui->SettingsButton, SIGNAL(clicked()), this, SLOT(toOptions()));
    connect(ui->MultiPlayerButton, SIGNAL(clicked()), this, SLOT(toMultiPlayer()));
    connect(ui->SinglePlayerButton, SIGNAL(clicked()), this, SLOT(toSinglePlayer()));
    connect(ui->QuitButton, SIGNAL(clicked()), this, SLOT(toExit()));
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

void MainMenuWidget::toOptions(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eOptions);
}

void MainMenuWidget::toMultiPlayer(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eMultiPlayer);
}

void MainMenuWidget::toSinglePlayer(){
    Game::instance()->openMenus()->selectMenu(MenuStack::eSinglePlayer);
}

void MainMenuWidget::toExit(){
    Game::instance()->destroy();
}
