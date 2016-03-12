#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "background.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    MovingBackground(this);

    CuriousCat(this);
    MadDog(this);
    LawnMower(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


