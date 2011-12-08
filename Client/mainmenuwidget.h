#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>

namespace Ui {
    class MainMenuWidget;
}

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = 0);
    ~MainMenuWidget();

private slots:

    void toOptions();
    void toMultiPlayer();
    void toSinglePlayer();
    void toExit();

private:
    Ui::MainMenuWidget *ui;
};

#endif // MAINMENUWIDGET_H
