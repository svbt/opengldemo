#include <QtGui/QApplication>
#include "MainWindow.h"

#include "accumebuffertest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    return a.exec();
}



