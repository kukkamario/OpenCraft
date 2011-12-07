#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QWidget>

namespace Ui {
    class SettingsMenu;
}

class SettingsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMenu(QWidget *parent = 0);
    ~SettingsMenu();

private:
    Ui::SettingsMenu *ui;
};

#endif // SETTINGSMENU_H
