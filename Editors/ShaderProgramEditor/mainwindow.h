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

private:
    Ui::MainWindow *ui;

    bool mChanged;
    QString mSavePath;

    bool saveShader(const QString &path);
    bool openShader(const QString &path);

    bool checkUnsaved();
    QString mDefaultVertexShader;
    QString mDefaultFragmentShader;
    bool trySave();
    void closeEvent(QCloseEvent *e);
private slots:
    void edit();
    void actionNew();
    void actionOpen();
    void actionSave();
    void actionSaveAs();

    void openVertexShader();
    void openFragmentShader();

    void saveVertexShader();
    void saveFragmentShader();
    void tryBuild();
};

#endif // MAINWINDOW_H
