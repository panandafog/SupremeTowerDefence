#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "level.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void close_clicked();
private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
private:
  Ui::MainWindow *ui_;
  //SecondWindow *level;
  Level *game;

};
#endif // MAINWINDOW_H
