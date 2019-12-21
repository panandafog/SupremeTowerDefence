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
  void on_playDemoButton_clicked();
  void on_playLevel1Button_clicked();
  void on_exitButton_clicked();
private:
  Ui::MainWindow *ui_;
  Level *level_;

};
#endif // MAINWINDOW_H
