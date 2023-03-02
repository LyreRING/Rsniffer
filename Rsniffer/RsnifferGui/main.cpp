#include <QApplication>
#include "mainwindow.h"

/******************************
    Main file of RsnifferGui
*******************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(w.windowFlags() & ~Qt::WindowMaximizeButtonHint);
    w.setFixedSize(775, 480);
    w.setWindowTitle("Rsniffer");
    w.show();
    
    return a.exec();
}
