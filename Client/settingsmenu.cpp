#include "settingsmenu.h"
#include "ui_settingsmenu.h"

SettingsMenu::SettingsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsMenu)
{
    ui->setupUi(this);
    ui->setAttribute(Qt::WA_OpaquePaintEvent);
}

SettingsMenu::~SettingsMenu()
{
    delete ui;
}
