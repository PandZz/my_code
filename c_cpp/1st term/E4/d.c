#include <stdio.h>

void convertToBin(int x)
{
    if (!x) return ;
    convertToBin(x >> 1);
    printf("%1d", x & 1);
    return ;
}

int main()
{
    double a;
    scanf("%lf", &a);
    convertToBin((int)a);
    if ((int)a == 0) putchar('0');
    a -= (int)a;
    putchar('.');
    for (int i = 1; i <= 10; ++i)
    {
        a *= 2;
        printf("%1d", (int)a);
        a -= (int)a;
    }
    return 0;
}