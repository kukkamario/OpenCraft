#ifndef SCREENSTATE_H
#define SCREENSTATE_H

class ScreenState
{
public:
    ScreenState(){}
    virtual ~ScreenState(){}
    virtual void load() = 0;
    virtual bool init() = 0;
    virtual void unload() = 0;
    virtual void mouseEvent(int button,int state,int x,int y) = 0;
    virtual void keyPressEvent(unsigned char key,int mouseX,int mouseY) = 0;
    virtual void keyReleaseEvent(unsigned char key,int mouseX,int mouseY) = 0;
    virtual void specialKeyPressEvent(int key,int mouseX,int mouseY) = 0;
    virtual void specialKeyReleaseEvent(int key,int mouseX,int mouseY) = 0;
    virtual void mouseWheelEvent(int wheel,int direction) = 0;
    virtual void render() = 0;
    virtual void windowResize(int w,int h) = 0;
    virtual const char *name() = 0;
};

#endif // SCREENSTATE_H