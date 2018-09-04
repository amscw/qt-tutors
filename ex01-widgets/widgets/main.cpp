#include "mainwindow.h"
#include <QApplication>

/**
 * @brief qMain
 * Для заполнения фона виджета сплошным цветом или растровым изображением
 * необходимо сначала создать объект палитры, а затем вызовом метода
 * setPlalette() установить его в виджете
 *
 * Виджет имеет важное СВОЙСТВО autoFillBackground, которое по умолчанию
 * равно false. Вследствие этого все потомки виджета не заполняются фоном и,
 * соответственно, невидимы.
 *
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // top-widget
    QWidget wgt;
    wgt.resize(200, 200);

    // child 1
    QWidget *pwgt1 = new QWidget(&wgt);
    QPalette pal1;
    pal1.setColor(pwgt1->backgroundRole(), Qt::blue);
    pwgt1->setPalette(pal1);
    pwgt1->resize(100, 100);
    pwgt1->move(25, 25);
    pwgt1->setAutoFillBackground(true);

    // child 2
    QWidget *pwgt2 = new QWidget(&wgt);
    QPalette pal2;
    pal2.setColor(pwgt2->backgroundRole(), Qt::red);
    pwgt2->setPalette(pal2);
    pwgt2->resize(100, 100);
    pwgt2->move(75, 75);
    pwgt2->setAutoFillBackground(true);

    wgt.show();
    return a.exec();
}
