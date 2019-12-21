#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "demo.h"

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

void MainWindow::on_playDemoButton_clicked()
{
  //SecondWindow *level = new SecondWindow;
  //level->showFullScreen();
  //this->close();
  level_ = new Demo();
  level_->show();
  this->close();

}

void MainWindow::on_playLevel1Button_clicked()
{
  //SecondWindow *level = new SecondWindow;
  //level->showFullScreen();
  //this->close();
  level_ = new Demo();
  level_->show();
  this->close();

}

void MainWindow::on_exitButton_clicked()
{
  this->close();
}
