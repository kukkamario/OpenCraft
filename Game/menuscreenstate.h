#ifndef MENUSCREENSTATE_H
#define MENUSCREENSTATE_H
#include "screenstate.h"
#include "gltexture2d.h"
#include "time.h"
#include "ocgui.h"

class MenuScreenState : public ScreenState
{
    Q_OBJECT
public:
    MenuScreenState(QObject *parent = 0);
    ~MenuScreenState();
    bool init(MainWindow *mainWindow);
    void load();
    void unload();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseWheelEvent(QWheelEvent *e){}

    void paintEvent(MainWindow *mainWindow);
    void paintGL(MainWindow *mainWindow);
    void windowResize(int w,int h);
    const char *name(){return "menu";}
    void selected();
    void update();
private:
    void setupGL(int w,int h);
    int mFPS;
    int mFPSCounter;
    clock_t mLastTime;
    OCGui mGui;

    bool mLoaded;
    float mWindowW;
    float mWindowH;
};

#endif // MENUSCREENSTATE_H
