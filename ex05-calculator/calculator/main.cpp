#include "mainwindow.h"
#include <QApplication>
#include "calc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calc_c calc;
    calc.setWindowTitle("Calculator");
    calc.resize(230, 300);
    calc.show();
    return a.exec();
}
