#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

#include "my.h"
#include "counter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    // simple signal-slot communication
    mysignal_c mysignal;
    myslot_c myslot;
    bool bOk = QObject::connect(&mysignal, SIGNAL(doIt(const QString &)), &myslot, SLOT(DidIt(const QString &)));
    Q_ASSERT(bOk);
    mysignal.sendSignal();

    // widget communication
    QLabel lbl{"0"};
    QPushButton cmd{"ADD"};
    counter_c counter;

    lbl.show();
    cmd.show();

    bOk = QObject::connect(&cmd, SIGNAL(clicked()), &counter, SLOT(slotInc()));
    Q_ASSERT(bOk);
    bOk = QObject::connect(&counter, SIGNAL(sigCounterChanged(int)), &lbl, SLOT(setNum(int)));
    Q_ASSERT(bOk);
    bOk = QObject::connect(&counter, SIGNAL(sigGoodbye()), &a, SLOT(quit()));
    Q_ASSERT(bOk);

    return a.exec();
}
