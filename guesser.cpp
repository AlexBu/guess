#include "guesser.h"
#include <QDebug>

Guesser::Guesser(QObject *parent)
    : QObject{parent}
{

}

void Guesser::pickCurrent()
{
    long total = candidates.size();
    qDebug() << "total " <<total << " in array";
    // set current guess number
    long index = rand() % total;
    Number &num = candidates[index];
    candidates.removeAt(index);
    setCurrent(num.ToQString());
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
}

void Guesser::initRound()
{
    m_round_value = 1;
    setRound(QString("%1").arg(m_round_value));
}

void Guesser::initAB()
{
    setValueA(0);
    setValueB(0);
}

void Guesser::nextRound()
{
    m_round_value++;
    setRound(QString("%1").arg(m_round_value));

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
    initRound();
    pickCurrent();
    initAB();
}

bool Guesser::guess(int a, int b)
{
    qDebug() << "guess one time " << a << b;
    qDebug() << "total " << candidates.size() << " numbers now";
    if(a == 4 && b == 0) {
        qDebug() << "success!";
        setResult("Great, see how I'm smart! Let's try again!");
        return true;
    } else if(a + b <= 4) {
        qDebug() << "filter";
        filterResult(a, b);
        // check left number
        if(candidates.size() == 0) {
            // display error page
            setResult("Oops, something is wrong! Let's try again!");
            return true;
        }
        pickCurrent();
        initAB();
        nextRound();
        return false;
    } else {
        // display error page
        setResult("Oops, something is wrong! Let's try again!");
        return true;
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

int Guesser::valueA() const
{
    return m_valueA;
}

void Guesser::setValueA(int newValueA)
{
    if(m_valueA == newValueA)
        return;
    m_valueA = newValueA;
    qDebug() << "set value A " << m_valueA;
    emit valueAChanged();
}

int Guesser::valueB() const
{
    return m_valueB;
}

void Guesser::setValueB(int newValueB)
{
    if(m_valueB == newValueB)
        return;
    m_valueB = newValueB;
    qDebug() << "set value B " << m_valueB;
    emit valueBChanged();
}


QString Guesser::round() const
{
    return m_round;
}

void Guesser::setRound(QString newRound)
{
    if (m_round == newRound)
        return;
    m_round = newRound;
    qDebug() << "set round " << m_round;
    emit roundChanged();
}

const QString Guesser::result() const
{
    return m_result;
}

void Guesser::setResult(QString newResult)
{
    if (m_result == newResult)
        return;
    m_result = newResult;
    emit resultChanged();
}
