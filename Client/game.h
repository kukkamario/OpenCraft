#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"

class Game
{
public:
    static Game *instance();
    bool init();
    void launch();
    void destroy();
private:
    Game();
    ~Game();
    MainWindow *mMainWindow;
};

#endif // GAME_H
