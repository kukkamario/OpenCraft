#ifndef SCREENSTATE_H
#define SCREENSTATE_H
#include <QObject>
class MainWindow;
class ScreenState : public QObject
{
    Q_OBJECT
public:
    ScreenState(QObject *parent = 0);
    virtual ~ScreenState(){}
    virtual void load() = 0;
    virtual bool init(MainWindow *mainWindow) = 0;
    virtual void unload() = 0;
    virtual void mouseEvent(int button,int state,int x,int y) = 0;
    virtual void keyPressEvent(unsigned char key,int mouseX,int mouseY) = 0;
    virtual void keyReleaseEvent(unsigned char key,int mouseX,int mouseY) = 0;
    virtual void specialKeyPressEvent(int key,int mouseX,int mouseY) = 0;
    virtual void specialKeyReleaseEvent(int key,int mouseX,int mouseY) = 0;
    virtual void mouseWheelEvent(int wheel,int direction) = 0;
    virtual void paintEvent(MainWindow *mainWindow) = 0;
    virtual void paintGL(MainWindow *mainWindow) = 0;
    virtual void windowResize(int w,int h) = 0;
    virtual const char *name() = 0;
    virtual void selected() = 0;
signals:
    void repaintGL();
};

#endif // SCREENSTATE_H
