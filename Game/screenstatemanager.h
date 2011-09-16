#ifndef SCREENSTATEMANAGER_H
#define SCREENSTATEMANAGER_H
#include <QList>
#include "screenstate.h"
class MainWindow;

class ScreenStateManager:public QObject
{
    Q_OBJECT
public:
    ScreenStateManager();
    ~ScreenStateManager();

    static ScreenStateManager *instance();

    bool init(int ww,int wh,MainWindow *mainwindow);
    void changeStateTo(const char * name);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseWheelEvent(QWheelEvent *e);
    void paintEvent(MainWindow *mainwindow);
    void paintGL(MainWindow *mainwindow);
    void windowResize(int w,int h);

private:
    QList<ScreenState*> mScreenStates;
    ScreenState *mActiveScreenState;
    int mWindowW,mWindowH;
};

#endif // SCREENSTATEMANAGER_H
