#include "mainwindow.h"
#include <QApplication>
#include "my.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    mysignal_c mysignal;
    myslot_c myslot;
    QObject::connect(&mysignal, SIGNAL(doIt(const QString &)), &myslot, SLOT(DidIt(const QString &)));
    mysignal.sendSignal();

    return a.exec();
}
