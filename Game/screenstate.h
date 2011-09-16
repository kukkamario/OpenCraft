#ifndef SCREENSTATE_H
#define SCREENSTATE_H
#include <QObject>
class QMouseEvent;
class MainWindow;
class QWheelEvent;
class QKeyEvent;

class ScreenState : public QObject
{
    Q_OBJECT
public:
    ScreenState(QObject *parent = 0);
    virtual ~ScreenState(){}
    virtual void load() = 0;
    virtual bool init(MainWindow *mainWindow) = 0;
    virtual void unload() = 0;
    virtual void mouseMoveEvent(QMouseEvent *event) = 0;
    virtual void mousePressEvent(QMouseEvent *event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event) = 0;
    virtual void keyPressEvent(QKeyEvent *event) = 0;
    virtual void keyReleaseEvent(QKeyEvent *event) = 0;
    virtual void mouseWheelEvent(QWheelEvent *e) = 0;
    virtual void paintEvent(MainWindow *mainWindow) = 0;
    virtual void paintGL(MainWindow *mainWindow) = 0;
    virtual void windowResize(int w,int h) = 0;
    virtual const char *name() = 0;
    virtual void selected() = 0;
signals:
    void repaintGL();
    void update();
};

#endif // SCREENSTATE_H
