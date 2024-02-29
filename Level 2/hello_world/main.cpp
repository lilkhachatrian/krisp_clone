#include "hello_world.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hello_world w;
    w.show();
    return a.exec();
}
