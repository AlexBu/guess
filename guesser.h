#ifndef GUESSER_H
#define GUESSER_H

#include <QObject>

class Guesser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)
public:
    explicit Guesser(QObject *parent = nullptr);

    int current() const;
    void setCurrent(int newCurrent);

private:
    void init_array(void);
    QVector<int> candidates;
    int m_current;

signals:

    void currentChanged();

public slots:
    void start(QString &in);
    void guess(QString &in);
    void end(QString &in);
};

#endif // GUESSER_H
