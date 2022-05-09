#ifndef GUESSER_H
#define GUESSER_H

#include <QObject>

class Guesser : public QObject
{
    Q_OBJECT
public:
    explicit Guesser(QObject *parent = nullptr);

signals:

public slots:
    void start(QString &in);
};

#endif // GUESSER_H
