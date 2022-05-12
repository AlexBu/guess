#include "number.h"

Number::Number(char n0, char n1, char n2, char n3)
    : n{n0,n1,n2,n3}
{
}

QString Number::ToQString(void)
{
    return QString("%1%2%3%4")
            .arg(n[0])
            .arg(n[1])
            .arg(n[2])
            .arg(n[3]);
}

void Number::calcAB(QString src, int &a, int &b)
{
    a = 0;
    b = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(src[i] == n[j]) {
                if(i == j) {
                    a++;
                } else {
                    b++;
                }
            }
        }
    }
}

bool Number::verifyAB(QString src, int a, int b)
{
    int real_a = 0;
    int real_b = 0;
    calcAB(src, real_a, real_b);
    return ((a == real_a) && (b == real_b));
}

void Number::setNumber(int num, int bit)
{
    if(bit >= 0 && bit < 4) {
        n[bit] = QChar(num % 10 + '0');
    }
}
