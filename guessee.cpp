#include "guessee.h"
#include <QDebug>

Guessee::Guessee(QObject *parent)
    : QObject{parent}, m_theNumber('0', '1', '2', '3')
{

}

void Guessee::initNumber()
{
    QList<int> digits;
    for(int i = 0; i < 10; i++) {
        digits.push_back(i);
    }
    srand(time(NULL));
    for(int i = 0; i < 4; i++) {
        // swap the last and a random
        int index = rand() % (9 - i);
        m_theNumber.setNumber(digits[index], i);
        digits[index] = digits[9 - i];
    }
}

void Guessee::initRound(void)
{
    m_round = 1;
}

void Guessee::nextRound(void)
{
    m_round++;
}

void Guessee::appendCalcResult(int a, int b)
{
    QString new_round_result = QString("    Round %1:\n    Guessed: %2%3%4%5, Result: %6A %7B\n")
            .arg(m_round).arg(m_valueN1).arg(m_valueN2).arg(m_valueN3).arg(m_valueN4)
            .arg(a).arg(b);
    setRecordGuesseeText(m_result + new_round_result);
}

void Guessee::initN4(void)
{
    setValueN1(0);
    setValueN2(1);
    setValueN3(2);
    setValueN4(3);
}

void Guessee::initRecord(void)
{
    setRecordGuesseeText("\n");
}

void Guessee::start(QString &in)
{
    qDebug() << "the button says: " << in;
    initNumber();
    initRound();
    initN4();
    initRecord();
}

bool Guessee::guess(void)
{
    int a = 0;
    int b = 0;
    if(m_valueN1 == m_valueN2 ||
            m_valueN1 == m_valueN3 ||
            m_valueN1 == m_valueN4 ||
            m_valueN2 == m_valueN3 ||
            m_valueN2 == m_valueN4 ||
            m_valueN3 == m_valueN4
            ) {
        setResultGuesseePage("Oops, something is wrong! Let's try again!");
        return true;
    }
    m_theNumber.calcAB(QString("%1%2%3%4")
                       .arg(m_valueN1)
                       .arg(m_valueN2)
                       .arg(m_valueN3)
                       .arg(m_valueN4),
                       a, b);
    appendCalcResult(a, b);
    if(a == 4 && b == 0) {
        setResultGuesseePage("Great, see how I'm smart! Let's try again!");
        return true;
    }
    if(m_round >= 8) {
        setResultGuesseePage("Oops, something is wrong! Let's try again!");
        return true;
    }
    nextRound();
    return false;
}

void Guessee::end(QString &in)
{
    qDebug() << "guessee ended " << in;
}


int Guessee::valueN1() const
{
    return m_valueN1;
}

void Guessee::setValueN1(int newValueN1)
{
    if (m_valueN1 == newValueN1)
        return;
    m_valueN1 = newValueN1;
    emit valueN1Changed();
}

int Guessee::valueN2() const
{
    return m_valueN2;
}

void Guessee::setValueN2(int newValueN2)
{
    if (m_valueN2 == newValueN2)
        return;
    m_valueN2 = newValueN2;
    emit valueN2Changed();
}

int Guessee::valueN3() const
{
    return m_valueN3;
}

void Guessee::setValueN3(int newValueN3)
{
    if (m_valueN3 == newValueN3)
        return;
    m_valueN3 = newValueN3;
    emit valueN3Changed();
}

int Guessee::valueN4() const
{
    return m_valueN4;
}

void Guessee::setValueN4(int newValueN4)
{
    if (m_valueN4 == newValueN4)
        return;
    m_valueN4 = newValueN4;
    emit valueN4Changed();
}

const QString Guessee::recordGuesseeText() const
{
    return m_result;
}

void Guessee::setRecordGuesseeText(QString newRecordGuesseeText)
{
    if (m_result == newRecordGuesseeText)
        return;
    m_result = newRecordGuesseeText;
    emit recordGuesseeTextChanged();
}

const QString Guessee::resultGuesseePage() const
{
    return m_resultGuesseePage;
}

void Guessee::setResultGuesseePage(QString newResultGuesseePage)
{
    if (m_resultGuesseePage == newResultGuesseePage)
        return;
    m_resultGuesseePage = newResultGuesseePage;
    emit resultGuesseePageChanged();
}
