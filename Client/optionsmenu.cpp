#include "optionsmenu.h"
#include "ui_optionsmenu.h"

OptionsMenu::OptionsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionsMenu)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
}

OptionsMenu::~OptionsMenu()
{
    delete ui;
}
