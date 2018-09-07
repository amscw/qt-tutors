#include "calc.h"
#include <QLCDNumber>
#include <QGridLayout>
#include <QPushButton>

calc_c::calc_c(QWidget *pwgt) : QWidget(pwgt), m_plcd(new QLCDNumber(12))
{
    m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd->setMinimumSize(150, 50);
    QChar aButtons[][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'0', '.', '=', '+'}
    };

    // Layout setup
    QGridLayout *ptopLayout = new QGridLayout;
    ptopLayout->addWidget(m_plcd, 0, 0, 1, 4);  // занимает 1 строку и 4 столбца
    ptopLayout->addWidget(createButton("CE"), 1, 3);

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            ptopLayout->addWidget(createButton(aButtons[i][j]), i+2, j);
    setLayout(ptopLayout);
}

QPushButton *calc_c::createButton(const QString &str)
{
    QPushButton *pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return pcmd;
}

void calc_c::calculate()
{
    qreal fOperand2 = m_stk.pop().toFloat();
    QString strOp = m_stk.pop();
    qreal fOperand1 = m_stk.pop().toFloat();
    qreal fResult = 0;
    if (strOp == "+") {
        fResult = fOperand1 + fOperand2;
    } else if (strOp == "-") {
        fResult = fOperand1 - fOperand2;
    } else if (strOp == "/") {
        fResult = fOperand1 / fOperand2;
    } else if (strOp == "*") {
        fResult = fOperand1 * fOperand2;
    }
    m_plcd->display(fResult);
}

void calc_c::slotButtonClicked()
{
    // какую кнопку нажали?
    QString str = qobject_cast<QPushButton*>(sender())->text();
    if (str == "CE")
    {
        // сброс
        m_stk.clear();
        m_strDisplay = "";
        m_plcd->display("0");
    } else if (str.contains(QRegExp("[0-9]"))) {
        // цифру
        m_strDisplay += str;
        m_plcd->display(m_strDisplay);
    } else if (str == ".") {
        // разделительную точку
        m_strDisplay += str;
        m_plcd->display(m_strDisplay);
    } else {
        // оператор
        if (m_stk.count() >= 2) {
            // в стеке есть как минимум 1 операнд и 1 оператор
            // кладем второй операнд и вычисляем
            m_stk.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stk.clear();
            // возвращаем результат на стек для продолжения вычислений
            m_stk.push(QString().setNum(m_plcd->value()));
            // кладем на стек следующий оператор
            if (str != "=")
                m_stk.push(str);
        } else {
            // 1-ый операнд введен, кладем его на стек
            m_stk.push(QString().setNum(m_plcd->value()));
            // кладем оператор на стек
            m_stk.push(str);
            // готовимся к вводу второго операнда
            m_strDisplay = "";
        }
    }
}
