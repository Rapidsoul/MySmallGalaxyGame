#include <QApplication>
#include "game.h"

/*
 * YAKUBOVICH SERHII, KB-14-1
 */

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();

    return a.exec();
}
