#ifndef GUESSEE_H
#define GUESSEE_H

#include <QObject>
#include "number.h"

class Guessee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int valueN1 READ valueN1 WRITE setValueN1 NOTIFY valueN1Changed)
    Q_PROPERTY(int valueN2 READ valueN2 WRITE setValueN2 NOTIFY valueN2Changed)
    Q_PROPERTY(int valueN3 READ valueN3 WRITE setValueN3 NOTIFY valueN3Changed)
    Q_PROPERTY(int valueN4 READ valueN4 WRITE setValueN4 NOTIFY valueN4Changed)
    Q_PROPERTY(QString recordGuesseeText READ recordGuesseeText WRITE setRecordGuesseeText NOTIFY recordGuesseeTextChanged)
    Q_PROPERTY(QString resultGuesseePage READ resultGuesseePage WRITE setResultGuesseePage NOTIFY resultGuesseePageChanged)

public:
    explicit Guessee(QObject *parent = nullptr);

    int valueN1() const;
    void setValueN1(int newValueN1);

    int valueN2() const;
    void setValueN2(int newValueN2);

    int valueN3() const;
    void setValueN3(int newValueN3);

    int valueN4() const;
    void setValueN4(int newValueN4);

    const QString recordGuesseeText() const;
    void setRecordGuesseeText(QString newRecordGuesseeText);

    const QString resultGuesseePage() const;
    void setResultGuesseePage(QString newResultGuesseePage);

private:
    void initNumber(void);
    void initRound(void);
    void appendCalcResult(int a, int b);
    Number m_theNumber;
    int m_valueN1;

    int m_valueN2;

    int m_valueN3;

    int m_valueN4;

    void initN4(void);
    QString m_result;
    int m_round;

    void nextRound();
    void initRecord();
    QString m_resultGuesseePage;

signals:

    void valueN1Changed();

    void valueN2Changed();

    void valueN3Changed();

    void valueN4Changed();

    void recordGuesseeTextChanged();

    void resultGuesseePageChanged();

public slots:
    void start(QString &in);
    bool guess(void);
    void end(QString &in);
};

#endif // GUESSEE_H

