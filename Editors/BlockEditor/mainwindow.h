#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

    void openBlock();
    void saveBlock();
    void saveBlockAs();

private:
    void setModified(bool t);//Asetettaan onko tiedostoa muutettu.
    bool canDestroy(); //Kysyy käyttäjältä voidaanko tallentamattomat tiedot tuhota. Palauttaa true jos sallitaan.
    bool saveBlock(const QString &path);//Varsinainen tallennusfunktio
    bool openBlock(const QString &path);
    Ui::MainWindow *ui;
    QString mFilePath; //Jos on ladattu tiedosto muokkauksessa tai tiedosto on jo kertaalleen avattu niin tiedoston sijainti
    bool mModified; //Onko tiedostoa muutettu.
};

#endif // MAINWINDOW_H
