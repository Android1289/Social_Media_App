#include "mainwindow.h"
#include"feed.h"
#include <QApplication>

int feed::share=0;
int feed::numofcmnts=22;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
