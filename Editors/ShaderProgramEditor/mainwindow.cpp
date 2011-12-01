#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>
#include <QTextStream>
#include <QCloseEvent>

#define MAGIC_NUMBER (0x01412533)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(actionNew()));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(actionOpen()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(actionSaveAs()));
    connect(ui->actionSave_as,SIGNAL(triggered()),this,SLOT(actionSaveAs()));
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(edit()));
    connect(ui->textEdit_2,SIGNAL(textChanged()),this,SLOT(edit()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(edit()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));


    connect(ui->actionSave_2,SIGNAL(triggered()),this,SLOT(saveVertexShader()));
    connect(ui->actionSave_3,SIGNAL(triggered()),this,SLOT(saveFragmentShader()));

    connect(ui->actionOpen_2,SIGNAL(triggered()),this,SLOT(openVertexShader()));
    connect(ui->actionOpen_3,SIGNAL(triggered()),this,SLOT(openFragmentShader()));
    connect(ui->actionBuild,SIGNAL(triggered()),this,SLOT(tryBuild()));

    this->setWindowTitle("OpenCraft shaderprogram editor - unnamed[*]");

    mChanged = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (!checkUnsaved()) {e->ignore();return;}
    e->accept();
}


void MainWindow::edit()
{
    this->setWindowModified(true);
    mChanged = true;
}

void MainWindow::actionNew()
{
    if (!checkUnsaved()) return;
    ui->lineEdit->setText("");
    ui->textEdit->setText(mDefaultVertexShader);
    ui->textEdit_2->setText(mDefaultFragmentShader);
    this->setWindowModified(false);
    this->setWindowTitle("OpenCraft shaderprogram editor - unnamed[*]");
    mChanged = false;
    mSavePath = "";
}

void MainWindow::actionOpen()
{
    if (!checkUnsaved()) return;
    QString path = QFileDialog::getOpenFileName(this,tr("Open shaderprogram"),"",tr("OpenCraft shaderprogram (*.ocsp)"));
    if (!path.isEmpty())
    {
        if (openShader(path))
        {
            mChanged = false;
            mSavePath = path;
            this->setWindowModified(false);
            this->setWindowTitle(QString("OpenCraft shaderprogram editor - ")+QFileInfo(path).fileName()+"[*]");
        }
    }
}

void MainWindow::actionSaveAs()
{
    QString path = QFileDialog::getSaveFileName(this,tr("Save shaderprogram"),"",tr("OpenCraft shaderprogram (*.ocsp)"));
    if (!path.isEmpty())
    {
        saveShader(path);
    }
}

void MainWindow::actionSave()
{
    trySave();
}

bool MainWindow::trySave()
{
    if (mSavePath.isEmpty())
    {
        QString path = QFileDialog::getSaveFileName(this,tr("Save shaderprogram"),"",tr("OpenCraft shaderprogram (*.ocsp)"));
        if (path.isEmpty())
        {
            return false;
        }

        return saveShader(path);
    }
    return saveShader(mSavePath);
}

bool MainWindow::checkUnsaved()
{
    if (mChanged)
    {
        int ret = QMessageBox::question(this,tr("Unsaved changes..."),tr("Your program has unsaved changes.\n Do you want to save them?"),QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel)
        {
            return false;
        }
        else if (ret == QMessageBox::Yes)
        {
            return trySave();
        }
    }
    return true;
}


bool MainWindow::openShader(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,tr("Can't open"),tr("Can't open program %1").arg(path));
        return false;
    }

    int magicnum = 0;
    QDataStream in(&file);
    in >> magicnum;
    if (magicnum != MAGIC_NUMBER)
    {
        QMessageBox::critical(this,tr("File is invalid"),tr("Can't open program %1").arg(path));
        file.close();
        return false;
    }

    int versionnum;
    in >> versionnum;
    if (versionnum != 0x00000001)
    {
        QMessageBox::critical(this,tr("Update your editor"),tr("File format is not supported by this version. \n Please update editor."));
        return false;
    }

    QString name;
    in >> name;

    QString vertexShader;
    QString fragmentShader;

    in >> vertexShader;
    in >> fragmentShader;

    ui->lineEdit->setText(name);
    ui->textEdit_2->setText(vertexShader);
    ui->textEdit->setText(fragmentShader);
    this->setWindowModified(false);
    this->setWindowTitle(QString("OpenCraft shaderprogram editor - ")+QFileInfo(path).fileName()+"[*]");
    mChanged = false;
    mSavePath = path;

    return true;
}

bool MainWindow::saveShader(const QString &path)
{
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this,tr("Invalid name"),tr("You have to set shaderprogram's name"));
        return false;
    }


    QFile file(path);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,tr("Can't save"),tr("Can't save program to %1").arg(path));
        return false;
    }
    QString vertexShader = ui->textEdit_2->toPlainText();
    QString fragmentShader = ui->textEdit->toPlainText();

    QDataStream out(&file);
    out << ((int)MAGIC_NUMBER); //Magicnumber...
    out << ((int)0x00000001); //Versionnumber...
    out << ui->lineEdit->text(); //Nimi...

    out << vertexShader;

    out << fragmentShader;

    file.close();


    mChanged = false;
    mSavePath = path;
    this->setWindowModified(false);
    this->setWindowTitle(QString("OpenCraft shaderprogram editor - ")+QFileInfo(path).fileName()+"[*]");
    return true;
}


void MainWindow::openVertexShader()
{
    if (!checkUnsaved()) return;
    QString path = QFileDialog::getOpenFileName(this,tr("Open vertex shader"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,tr("Can't open file"),tr("Can't open file %1").arg(path));
            return;
        }
        QTextStream stream ( &file );
        QString vertexShader;
        while( !stream.atEnd() ) {
            vertexShader += stream.readLine() + "\n";

        }
        file.close(); // when your done.

        ui->textEdit_2->setPlainText(vertexShader);
    }
}

void MainWindow::openFragmentShader()
{
    if (!checkUnsaved()) return;
    QString path = QFileDialog::getOpenFileName(this,tr("Open fragment shader"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,tr("Can't open file"),tr("Can't open file %1").arg(path));
            return;
        }
        QTextStream stream ( &file );
        QString fragmentShader;
        while( !stream.atEnd() ) {
            fragmentShader += stream.readLine() + "\n";

        }
        file.close(); // when your done.

        ui->textEdit->setPlainText(fragmentShader);
    }
}

void MainWindow::saveVertexShader()
{
    QString path = QFileDialog::getSaveFileName(this,tr("Save vertex shader"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this,tr("Can't write to file"),tr("Can't write to file %1").arg(path));
            return;
        }

        QStringList lines = ui->textEdit_2->toPlainText().split("\n");

        QTextStream stream ( &file );
        foreach (QString line,lines)
        {
            stream << line << "\n";
        }
        file.close();

    }
}

void MainWindow::saveFragmentShader()
{
    QString path = QFileDialog::getSaveFileName(this,tr("Save fragment shader"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this,tr("Can't write to file"),tr("Can't write to file %1").arg(path));
            return;
        }

        QStringList lines = ui->textEdit->toPlainText().split("\n");

        QTextStream stream ( &file );
        foreach (QString line,lines)
        {
            stream << line << "\n";
        }
        file.close();

    }
}

void MainWindow::tryBuild()
{
    //Kesken
}
