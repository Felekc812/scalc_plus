#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    S21::calk model;
    S21::Controller controller(&model);
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
