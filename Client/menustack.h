#ifndef MENUSTACK_H
#define MENUSTACK_H
#include <QGraphicsScene>

class MenuStack : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MenuStack(QObject *parent = 0);
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

    void selectMenu(MenuState menu);
    void resize(int w,int h);
signals:


public slots:
private:
    QGraphicsProxyWidget *mCurrent;
    MenuState mCurrentMenuState;

};

#endif // MENUSTACK_H
