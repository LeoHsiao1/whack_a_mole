#include "whackamole.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WhackAMole w;
    w.show();

    return a.exec();
}
