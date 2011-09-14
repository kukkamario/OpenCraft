
#include <QApplication>
#include "screenstatemanager.h"
#include "mainwindow.h"
#include "glinclude/glinclude.h"


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    QApplication app(argc,argv);
    MainWindow window;

    if (!ScreenStateManager::instance()->init(window.width(),window.height(),&window))
    {
        qCritical("Can't initialize ScreenStateManager.");
        return 1;
    }
    loadExtension(window.context());
    window.show();
    return app.exec();
    return 0;
}
