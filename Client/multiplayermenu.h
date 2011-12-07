#ifndef MULTIPLAYERMENU_H
#define MULTIPLAYERMENU_H

#include <QWidget>

namespace Ui {
    class MultiPlayerMenu;
}

class MultiPlayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MultiPlayerMenu(QWidget *parent = 0);
    ~MultiPlayerMenu();
private slots:
    void toMainMenu();
private:
    Ui::MultiPlayerMenu *ui;
};

#endif // MULTIPLAYERMENU_H
