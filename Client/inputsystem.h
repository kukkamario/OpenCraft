#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H
#include <QObject>
#include <QEvent>

class InputSystem:public QObject
{
    Q_OBJECT
public:
    InputSystem(QObject *parent);

    /**
      *Tutkii QEventin ja ottaa tiedot talteen mikäli se on syöte.
    */
    bool handleEvent(const QEvent *event);

    /**
      *
      */
    void waitAnyInput();

private:

signals:
    void inputGet();


};

#endif // INPUTSYSTEM_H
