#include "guessee.h"
#include <QDebug>

Guessee::Guessee(QObject *parent)
    : QObject{parent}
{

}

void Guessee::start(QString &in)
{
    qDebug() << "the button says: " << in;
}

