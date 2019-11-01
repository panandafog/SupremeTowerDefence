#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    level = new SecondWindow();
    //connect(level, &SecondWindow::mainWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SecondWindow *level = new SecondWindow;
    level->showFullScreen();
    //this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
