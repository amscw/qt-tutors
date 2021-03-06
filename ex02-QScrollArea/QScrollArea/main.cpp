#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScrollArea sa;
    QWidget *pwgt = new QWidget;
    QPixmap pix("M:\\git\\qt-tutors\\ex02-QScrollArea\\QScrollArea\\img.jpg");
    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pix));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    pwgt->setFixedSize(pix.width(), pix.height());
    sa.setWidget(pwgt);
    sa.resize(350, 150);
    sa.show();

    return a.exec();
}
