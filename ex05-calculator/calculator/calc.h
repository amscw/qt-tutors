#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QStack>

class QLCDNumber;
class QPushButton;

class calc_c : public QWidget
{
    Q_OBJECT

private:
    QLCDNumber *m_plcd;
    QStack<QString> m_stk;
    QString m_strDisplay;

public:
    calc_c(QWidget *pwgt = nullptr);
    virtual ~calc_c(){}
    QPushButton *createButton(const QString &str);
    void calculate();

public slots:
    void slotButtonClicked();
};

#endif // CALC_H
