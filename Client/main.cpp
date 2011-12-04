#include <QtGui/QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setGraphicsSystem("opengl");
    int returnCode = -1;
    if (Game::instance()->init())//Jos alustus onnistui
    {
        Game::instance()->launch();//Käynnistetään peli
        returnCode = a.exec();//Aloitetaan eventlooppi
    }
    Game::instance()->destroy();//Tuhotaan kaikki
    return returnCode;
}
