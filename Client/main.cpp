#include <QtGui/QApplication>
#include "game.h"


int main(int argc, char *argv[])
{
    QApplication::setGraphicsSystem("opengl");
    Game g(argc, argv);
    int returnCode = -1;
    if (g.init())//Jos alustus onnistui
    {
        g.launch();//K‰ynnistet‰‰n peli
        returnCode = g.exec();//Aloitetaan eventlooppi
    }
    g.destroy();//Tuhotaan kaikki
    return returnCode;
}
