#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <QWidget>

namespace Ui {
    class OptionsMenu;
}

class OptionsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsMenu(QWidget *parent = 0);
    ~OptionsMenu();

private:
    Ui::OptionsMenu *ui;
};

#endif // OPTIONS_H
