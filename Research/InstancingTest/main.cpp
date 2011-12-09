#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QMessageBox>

void handler(QtMsgType type,const char*msg)
{
     switch (type) {
     case QtDebugMsg:
         QMessageBox::information(NULL,"Debug",msg);
         break;
     case QtWarningMsg:
         QMessageBox::warning(NULL,"Warning",msg);
         break;
     case QtCriticalMsg:
         QMessageBox::critical(NULL,"Critical",msg);
         break;
     case QtFatalMsg:
         QMessageBox::critical(NULL,"Fatal",msg);
         abort();
     }

}

int main(int argc, char *argv[])
{
    //qInstallMsgHandler(handler);
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(resource);
    QGLFormat format;
    format.setVersion(3,0);
    format.setDoubleBuffer(true);
    format.setAlpha(true);
    format.setSwapInterval(0);
    MainWindow *w = new MainWindow(format);
    w->show();

    int ret =a.exec();
    delete w;
    return ret;
}
