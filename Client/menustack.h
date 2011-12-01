#ifndef MENUSTACK_H
#define MENUSTACK_H


#include <QStackedWidget>
#include <QWidget>
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
        eNetConnectionOptions
    };

signals:

public slots:

};

#endif // MENUSTACK_H
