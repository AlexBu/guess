#ifndef NUMBER_H
#define NUMBER_H

#include <QString>


class Number
{
public:
    explicit Number(char n0, char n1, char n2, char n3);
    QString ToQString(void);
    bool verifyAB(QString src, int a, int b);
    void setNumber(int num, int bit);

    void calcAB(QString src, int &a, int &b);
private:
    QChar n[4];
};

#endif // NUMBER_H
