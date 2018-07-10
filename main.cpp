#include "eresmamainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EresmaMainWindow w;
    w.show();

    return a.exec();
}
