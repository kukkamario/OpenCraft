#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>


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


void MainWindow::saveBlock(){

}

void MainWindow::openBlock(){
    QString file = QFileDialog::getOpenFileName(this, tr("Open Block file"), "", tr("TWC Block file (*.tvcb)"));
    if(!file.isEmpty()){

    }
}

void MainWindow::saveBlockAs(){

    QString file = QFileDialog::getSaveFileName(this, tr("Save Block file"), "", tr("TWC Block file (*.tvcb)"));
    if(!file.isEmpty()){

    }

}
