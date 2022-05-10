#ifndef GUESSEE_H
#define GUESSEE_H

#include <QObject>

class Guessee : public QObject
{
    Q_OBJECT
public:
    explicit Guessee(QObject *parent = nullptr);

signals:

public slots:
    void start(QString &in);
};

#endif // GUESSEE_H

