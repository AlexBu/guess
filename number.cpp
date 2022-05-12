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

bool Number::verifyAB(QString src, int a, int b) const
{
    int real_a = 0;
    int real_b = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(src[i] == n[j]) {
                if(i == j) {
                    real_a++;
                } else {
                    real_b++;
                }
            }
        }
    }
    return ((a == real_a) && (b == real_b));
}
