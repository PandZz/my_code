#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int gcd(int a, int b, int* x, int* y)
{
    if (!b)
    {
        *x = 1, *y = 0;
        return a;
    }
    int d = gcd(b, a % b, x, y), tmp = *x;
    *x = *y, *y = tmp - a / b * (*y);
    return d;
}

int main()
{
    int a, b, x, y, d;
    scanf("%d%d", &a, &b);
    d = gcd(a, b, &x, &y);
    printf("%d = %d*(%d) + %d*(%d)\n", d, a, x, b, y);
    return 0;
}