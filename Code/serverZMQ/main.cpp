#include "game.h"
#include <QCoreApplication>

int main( int argc, char *argv[] )
{

    QCoreApplication a(argc, argv);
    new game(&a);
    return a.exec();
}
