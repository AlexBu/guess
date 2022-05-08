#ifndef GUESSER_H
#define GUESSER_H

#include "qqmlregistration.h"
#include <QObject>

class Guesser : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Guesser(QObject *parent = nullptr);

signals:

};

#endif // GUESSER_H
