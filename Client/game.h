#ifndef GAME_H
#define GAME_H
#include <QApplication>


/**
  * Pieni makro helpottamaan el‰m‰‰
  */
#define GameI (Game::instance())

class MainWindow;
class MenuStack;
class InputSystem;

class Game: public QApplication
{
    Q_OBJECT
public:
    Game(int argc, char *argv[]);
    ~Game();
    static Game *instance();
    bool init();
    void launch();
    void destroy();
    MenuStack *openMenus();
    void closeMenus();
    MainWindow *mainWindow(){return mMainWindow;}
    InputSystem *inputSystem();
private:
    MainWindow *mMainWindow;
    InputSystem *mInputSystem;


private slots:
    void mainWindowDeleted();
};

#endif // GAME_H
