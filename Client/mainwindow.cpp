#include "mainwindow.h"
#include <QResizeEvent>
#include <QPushButton>
#include <QGraphicsScene>
#include "glcontext.h"

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    this->setViewport(new GLContext);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    openMenus()->selectMenu(MenuStack::eMainMenu);
}

MainWindow::~MainWindow()
{

}



void MainWindow::resizeEvent(QResizeEvent *e)
{
    ((MenuStack*)scene())->resize(e->size().width(),e->size().height());
}




void MainWindow::drawBackground(QPainter *painter, const QRectF &rect)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glDisable(GL_DEPTH_TEST);
}

MenuStack *MainWindow::openMenus()
{
    if (!scene())
    {
        setScene(new MenuStack);
    }
    return (MenuStack*)scene();
}

void MainWindow::closeMenus()
{
    if (scene()) delete scene();
    setScene(0);
}
