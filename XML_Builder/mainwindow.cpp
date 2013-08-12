#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,
                       const QString& dirName) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    label = new QLabel(dirName, this);
//    resize(600,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
