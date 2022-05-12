#include "guesser.h"
#include <QDebug>

Guesser::Guesser(QObject *parent)
    : QObject{parent}
{

}

void Guesser::initArray()
{
    // initialize the number list
    candidates.clear();
    for(int i = 123; i < 9977; i++) {
        int n[4];
        n[0] = i/1000;
        n[1] = (i/100)%10;
        n[2] = (i/10)%10;
        n[3] = i%10;
        if( n[0] != n[1] &&
            n[0] != n[2] &&
            n[0] != n[3] &&
            n[1] != n[2] &&
            n[2] != n[3] &&
            n[1] != n[3]
          ) {
            Number num(n[0]+'0', n[1]+'0', n[2]+'0', n[3]+'0');
            candidates.push_back(num);
        }
    }
    long total = candidates.size();
    Number &num = candidates[rand()%total];
    setCurrent(num.ToQString());
    qDebug() << "total " <<total << " in array";
}

void Guesser::filterResult(int a, int b)
{
    // a + b <= 4 && a != 4
    backup_candidates.clear();
    QList<Number>::const_iterator iter;
    for (iter = candidates.cbegin(); iter != candidates.cend(); ++iter) {
        if( iter->verifyAB(m_current, a, b) == true) {
            backup_candidates.push_back(*iter);
        }
    }
    candidates.swap(backup_candidates);
    qDebug() << "total " << candidates.size() << " numbers after filtering";
}

void Guesser::start(QString &in)
{
    qDebug() << "the button says: " << in;
    initArray();
}

void Guesser::guess(int a, int b)
{
    qDebug() << "guess one time " << a << b;
    qDebug() << "total " << candidates.size() << " numbers now";
    if(a == 4 && b == 0) {
        qDebug() << "success!";
    } else if(a + b <= 4) {
        qDebug() << "filter";
        filterResult(a, b);
    } else {
        qDebug() << "error in AB values!";
    }
}

void Guesser::end(QString &in)
{
    qDebug() << "guess ended " << in;
}

QString Guesser::current() const
{
    return m_current;
}

void Guesser::setCurrent(QString newCurrent)
{
    if (m_current == newCurrent)
        return;
    m_current = newCurrent;
    qDebug() << "set current " << m_current;
    emit currentChanged();
}
