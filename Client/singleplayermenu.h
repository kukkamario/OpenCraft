#ifndef SINGLEPLAYERMENU_H
#define SINGLEPLAYERMENU_H

#include <QWidget>

namespace Ui {
    class SinglePlayerMenu;
}

class SinglePlayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SinglePlayerMenu(QWidget *parent = 0);
    ~SinglePlayerMenu();
private slots:
    void toMainMenu();
private:
    Ui::SinglePlayerMenu *ui;
};

#endif // SINGLEPLAYERMENU_H
