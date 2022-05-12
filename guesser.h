#ifndef GUESSER_H
#define GUESSER_H

#include <QObject>
#include "number.h"

class Guesser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString current READ current WRITE setCurrent NOTIFY currentChanged)
    Q_PROPERTY(QString round READ round WRITE setRound NOTIFY roundChanged)
    Q_PROPERTY(QString result READ result WRITE setResult NOTIFY resultChanged)
    Q_PROPERTY(int valueA READ valueA WRITE setValueA NOTIFY valueAChanged)
    Q_PROPERTY(int valueB READ valueB WRITE setValueB NOTIFY valueBChanged)
public:
    explicit Guesser(QObject *parent = nullptr);

    QString current() const;
    void setCurrent(QString newCurrent);

    int valueA() const;
    void setValueA(int newValueA);

    int valueB() const;
    void setValueB(int newValueB);

    QString round() const;
    void setRound(QString newRound);

    const QString result() const;
    void setResult(QString newResult);

private:
    void initArray(void);
    void initRound(void);
    void initAB(void);
    void nextRound(void);
    void filterResult(int a, int b);

    QList<Number> candidates, backup_candidates;
    QString m_current;

    int m_valueA;

    int m_valueB;

    void pickCurrent();

    QString m_round;

    int m_round_value;

    QString m_result;

signals:

    void currentChanged();

    void valueAChanged();

    void valueBChanged();

    void roundChanged();

    void resultChanged();

public slots:
    void start(QString &in);
    bool guess(int a, int b);
    void end(QString &in);
};

#endif // GUESSER_H
