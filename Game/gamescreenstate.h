#ifndef GAMESCREENSTATE_H
#define GAMESCREENSTATE_H
#include "screenstate.h"
#include "glpainter.h"

class GameScreenState : public ScreenState
{
    Q_OBJECT
public:
    GameScreenState(QObject *parent = 0);
    ~GameScreenState();
    bool init(MainWindow *mainWindow);
    void load();
    void unload();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseWheelEvent(QWheelEvent *e);
    void paintGL(MainWindow *mainWindow);
    void paintEvent(MainWindow *mainWindow);
    void windowResize(int w,int h);
    void selected();
    void update();
    const char *name(){return "menu";}
private:
    glPainter mPainter;
};

#endif // GAMESCREENSTATE_H
