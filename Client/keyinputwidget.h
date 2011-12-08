#ifndef KEYINPUTWIDGET_H
#define KEYINPUTWIDGET_H

#include <QDialog>
#include <QString>
class KeyInputWidget : public QDialog
{
    int mSelectedKey;
    int mSelectedButton;
    QString mKeyName;
public:
    KeyInputWidget(QString title = "");
public slots:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
};

#endif // KEYINPUTWIDGET_H
