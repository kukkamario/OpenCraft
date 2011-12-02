#ifndef MENUSTACK_H
#define MENUSTACK_H
#include <QStackedWidget>

#include <QStackedWidget>

class MenuStack : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MenuStack(QWidget *parent = 0);
    enum MenuState{
        eMainMenu = 0,
        eSinglePlayer,
        eMultiPlayer,
        ePauseMenu,
        eOptions,
        eModsAndTextures,
        eVideoOptions,
        eSoundOptions,
        eNetConnectionOptions,
        eMenuStateCount
    };
    void insertWidget(int index ,QWidget* widget);
    void widget(int index);

    void openMenu(MenuState menu);
    void hideMenu();
signals:

public slots:
private:
    QWidget *mMenus[eMenuStateCount];

};

#endif // MENUSTACK_H
