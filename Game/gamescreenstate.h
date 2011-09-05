#ifndef GAMESCREENSTATE_H
#define GAMESCREENSTATE_H
#include "screenstate.h"
#include "glpainter.h"

class GameScreenState : public ScreenState
{
public:
    GameScreenState();
    ~GameScreenState();
    bool init();
    void load();
    void unload();
    void mouseEvent(int button,int state,int x,int y);
    void keyPressEvent(unsigned char key,int mouseX,int mouseY);
    void keyReleaseEvent(unsigned char key,int mouseX,int mouseY);
    void specialKeyPressEvent(int key,int mouseX,int mouseY);
    void specialKeyReleaseEvent(int key,int mouseX,int mouseY);
    void mouseWheelEvent(int wheel,int direction);
    void render();
    void windowResize(int w,int h);
    const char *name(){return "menu";}
private:
    glPainter mPainter;
};

#endif // GAMESCREENSTATE_H
