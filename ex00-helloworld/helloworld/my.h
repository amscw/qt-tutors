#ifndef MY_H
#define MY_H

#include <QObject>
#include <QDebug>

class mysignal_c : public QObject
{
    Q_OBJECT

public:
    virtual ~mysignal_c(){}
    void sendSignal() noexcept { emit doIt("hello, world!"); }

signals:
    void doIt(const QString &);
};

class myslot_c : public QObject
{
    Q_OBJECT

public:
    virtual ~myslot_c(){}

protected slots:
    void DidIt(const QString &str) const noexcept
    {
        qDebug() << "catch the doIt signal!";
        qDebug() << str;
    }
};

#endif // MY_H
