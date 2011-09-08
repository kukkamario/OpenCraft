#ifndef SCREENSTATEMANAGER_H
#define SCREENSTATEMANAGER_H
#include <QList>
#include "screenstate.h"

class ScreenStateManager
{
public:
    ScreenStateManager();
    ~ScreenStateManager();

    static ScreenStateManager *instance();

    bool init(int ww,int wh);
    void changeStateTo(const char * name);

    void mouseEvent(int button,int state,int x,int y);
    void keyPressEvent(unsigned char key,int mouseX,int mouseY);
    void keyReleaseEvent(unsigned char key,int mouseX,int mouseY);
    void specialKeyPressEvent(int key,int mouseX,int mouseY);
    void specialKeyReleaseEvent(int key,int mouseX,int mouseY);
    void mouseWheelEvent(int wheel,int direction);
    void render();
    void windowResize(int w,int h);

private:
    QList<ScreenState*> mScreenStates;
    ScreenState *mActiveScreenState;
    int mWindowW,mWindowH;
};

#endif // SCREENSTATEMANAGER_H
