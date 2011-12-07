#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openBlock()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(saveBlockAs()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::saveBlock()
{
    if (mFilePath.isEmpty()) //Ei aikaisempaa tallennuspaikkaa
    {
        saveBlockAs();
        return;
    }
    saveBlock(mFilePath);
}

void MainWindow::openBlock()
{
    if (!canDestroy()) return;
    QString file = QFileDialog::getOpenFileName(this, tr("Open Block file"), "", tr("TWC Block file (*.tvcb)"));
    if(!file.isEmpty()){
        openBlock(file);
    }
}

void MainWindow::saveBlockAs(){

    QString file = QFileDialog::getSaveFileName(this, tr("Save Block file"), "", tr("TWC Block file (*.tvcb)"));
    if(!file.isEmpty()){
        saveBlock(file);
    }

}


bool MainWindow::canDestroy()
{
    if (!mModified) return true;

    QMessageBox::StandardButton pressed = QMessageBox::question(this,tr("Save changes"),tr("File has unsaved changes."),QMessageBox::Discard | QMessageBox::Save | QMessageBox::Cancel);
    switch (pressed)
    {
    case QMessageBox::Cancel:
        return false;
    case QMessageBox::Save:
        saveBlock();
        return !mModified; //Jos tallennus onnistui niin mModifiedin pitäisi olla false.
    case QMessageBox::Discard:
        return true;
    }
}


bool MainWindow::saveBlock(const QString &path)
{

    return true;
}

bool MainWindow::openBlock(const QString &path)
{

    return true;
}
