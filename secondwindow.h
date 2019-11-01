#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SecondWindow; }
QT_END_NAMESPACE

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
//signals:
//    void mainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
