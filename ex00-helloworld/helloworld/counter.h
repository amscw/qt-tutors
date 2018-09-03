#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class counter_c : public QObject
{
    Q_OBJECT

private:
    int m_nValue;

public:
    counter_c() noexcept;
    virtual ~counter_c() noexcept{}

protected slots:
    void slotInc() noexcept;

signals:
    void sigGoodbye();
    void sigCounterChanged(int);

};

#endif // COUNTER_H
