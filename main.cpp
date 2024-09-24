#include "utterchat.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UtterChat w;
    w.show();
    return a.exec();
}
