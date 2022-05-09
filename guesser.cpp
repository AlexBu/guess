#include "guesser.h"
#include <QDebug>

Guesser::Guesser(QObject *parent)
    : QObject{parent}
{

}

void Guesser::start(QString &in)
{
    qDebug() << "the button says: " << in;
}
