#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"

class Game:public QObject
{
    Q_OBJECT
public:
    static Game *instance();
    bool init();
    void launch();
    void destroy();
private:
    Game();
    ~Game();
    MainWindow *mMainWindow;
private slots:
    void mainWindowDeleted();
};

#endif // GAME_H
