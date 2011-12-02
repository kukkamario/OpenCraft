#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/QGLWidget>
#include "menustack.h"
#include "mainmenuwidget.h"
class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    MenuStack mMenuStates;
    MainMenuWidget mMainMenu;

    ~MainWindow();
};

#endif // MAINWINDOW_H
