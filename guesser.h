#ifndef GUESSER_H
#define GUESSER_H

#include <QObject>
#include "number.h"

class Guesser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString current READ current WRITE setCurrent NOTIFY currentChanged)
public:
    explicit Guesser(QObject *parent = nullptr);

    QString current() const;
    void setCurrent(QString newCurrent);

private:
    void initArray(void);
    void filterResult(int a, int b);

    QList<Number> candidates, backup_candidates;
    QString m_current;

signals:

    void currentChanged();

public slots:
    void start(QString &in);
    void guess(int a, int b);
    void end(QString &in);
};

#endif // GUESSER_H
