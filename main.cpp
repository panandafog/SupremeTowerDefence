#include "mainwindow.h"
#include <QApplication>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new Game();

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
