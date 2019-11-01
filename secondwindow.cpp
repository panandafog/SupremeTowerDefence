#include "secondwindow.h"
#include "mainwindow.h"
#include "ui_secondwindow.h"
#include <iostream>

SecondWindow::SecondWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    //emit mainWindow();
    this->close();
}
