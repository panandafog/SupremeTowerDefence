#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

extern Game *game;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui_(new Ui::MainWindow)
{
  ui_->setupUi(this);
  //level = new SecondWindow();
  //connect(level, &SecondWindow::mainWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
  delete ui_;
}

void MainWindow::on_pushButton_clicked()
{
  //SecondWindow *level = new SecondWindow;
  //level->showFullScreen();
  //this->close();

  game->show();
  this->close();

}

void MainWindow::on_pushButton_2_clicked()
{
  this->close();
}
