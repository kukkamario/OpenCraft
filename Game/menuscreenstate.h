#ifndef MENUSCREENSTATE_H
#define MENUSCREENSTATE_H
#include "screenstate.h"

class MenuScreenState : public ScreenState
{
public:
    MenuScreenState();
    ~MenuScreenState();
    bool init();
    void load();
    void unload();
    void mouseEvent(int button,int state,int x,int y);
    void keyPressEvent(unsigned char key,int mouseX,int mouseY);
    void keyReleaseEvent(unsigned char key,int mouseX,int mouseY);
    void specialKeyPressEvent(int key,int mouseX,int mouseY);
    void specialKeyReleaseEvent(int key,int mouseX,int mouseY);
    void mouseWheelEvent(int wheel,int direction){} //Tuskin tarvitaan tätä...
    void render();
    void windowResize(int w,int h);
    const char *name(){return "menu";}
private:

};

#endif // MENUSCREENSTATE_H
