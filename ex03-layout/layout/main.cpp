#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    wgt.setObjectName("top_wgt");
    QPushButton *pcmdA = new QPushButton("A");
    QPushButton *pcmdB = new QPushButton("B");
    QPushButton *pcmdC = new QPushButton("C");

    // Layout setup
    QBoxLayout *pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addWidget(pcmdA, 1); // слабо тянучий
    pbxLayout->addWidget(pcmdB, 2); // средне тянучий
    pbxLayout->addStretch(2);       // добавить фактор растяжения ("пружину")
    pbxLayout->addWidget(pcmdC, 3); // сильно тянучий

    // добовать компоновку
    wgt.setLayout(pbxLayout);
    wgt.resize(450, 40);
    wgt.show();

    qDebug().nospace() << "a parent of pcmdA is " << pcmdA->parent()->objectName();

    return a.exec();
}
