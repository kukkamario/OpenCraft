#ifndef CONTROLSETTINGSMENU_H
#define CONTROLSETTINGSMENU_H

#include <QWidget>

namespace Ui {
    class ControlSettingsMenu;
}

class ControlSettingsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ControlSettingsMenu(QWidget *parent = 0);
    ~ControlSettingsMenu();
private slots:
     void toSettingsMenu();
     void toMainMenu();

     void setForwardKey();
     /*
     void setBackwardKey();
     void setLeftKey();
     void setRightKey();
     */
private:
    Ui::ControlSettingsMenu *ui;
};

#endif // CONTROLSETTINGSMENU_H
