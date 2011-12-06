#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}
