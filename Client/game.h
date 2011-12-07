#ifndef GAME_H
#define GAME_H
class MainWindow;
class MenuStack;
class Game: public QObject
{
    Q_OBJECT
public:
    static Game *instance();
    bool init();
    void launch();
    void destroy();
    MenuStack *openMenus();
    void closeMenus();

private:
    Game();
    ~Game();
    MainWindow *mMainWindow;

private slots:
    void mainWindowDeleted();
};

#endif // GAME_H
