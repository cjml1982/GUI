#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MinerGUI");
    QIcon icon("./MinerPhoto.jpeg");
    w.setWindowIcon(icon);
    w.show();

    return a.exec();
}


