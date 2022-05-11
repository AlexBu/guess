#include "guesser.h"
#include <QDebug>

Guesser::Guesser(QObject *parent)
    : QObject{parent}
{

}

void Guesser::init_array()
{
    candidates.clear();
    for(int i = 1234; i < 9977; i++) {
        int n[4];
        n[0] = i/1000;
        n[1] = (i/100)%10;
        n[2] = (i/10)%10;
        n[3] = i%10;
        if( n[0] != n[1] &&
            n[0] != n[2] &&
            n[0] != n[3] &&
            n[1] != n[2] &&
            n[2] != n[3]
          ) {
            candidates.push_back(i);
        }
    }
    long total = candidates.size();
    setCurrent(candidates[rand()%total]);
    qDebug() << "total " <<total << " in array";
}

void Guesser::start(QString &in)
{
    qDebug() << "the button says: " << in;
    // initialize the number list
    init_array();
}

void Guesser::guess(QString &in)
{
    qDebug() << "guess one time " << in;
}

void Guesser::end(QString &in)
{
    qDebug() << "guess ended " << in;
}

int Guesser::current() const
{
    return m_current;
}

void Guesser::setCurrent(int newCurrent)
{
    if (m_current == newCurrent)
        return;
    m_current = newCurrent;
    qDebug() << "set current " << m_current;
    emit currentChanged();
}
