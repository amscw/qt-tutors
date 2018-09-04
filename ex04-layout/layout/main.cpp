#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    QPushButton *ppbA = new QPushButton("A");
    QPushButton *ppbB = new QPushButton("B");
    QPushButton *ppbC = new QPushButton("C");
    QPushButton *ppbD = new QPushButton("D");

    QVBoxLayout *pvbxLayout = new QVBoxLayout;
    QHBoxLayout *phbxLayout = new QHBoxLayout;

    phbxLayout->setContentsMargins(5, 5, 5, 5); // отсутпы от краев
    phbxLayout->setSpacing(15);                 // зазоры

    // добавляем виджеты в горизонтальную компоновку:
    phbxLayout->addWidget(ppbC);
    phbxLayout->addWidget(ppbD);

    pvbxLayout->setContentsMargins(5, 5, 5, 5);
    pvbxLayout->setSpacing(15);

    // добавляем виджеты в вертикальную компоновку:
    pvbxLayout->addWidget(ppbA);
    pvbxLayout->addWidget(ppbB);
    // сюда же добавляем горизонатльную компоновку
    pvbxLayout->addLayout(phbxLayout);

    // назначить вертикальную компоновку главному виджету:
    wgt.setLayout(pvbxLayout);
    wgt.show();

    return a.exec();
}
