#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

double f(int op, int t)
{
    if (!op) return 9.0 * t / 5.0 + 32.0;
    else return 5.0 / 9.0 * (t - 32.0);
}

int main()
{
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    F(i, l, r) printf("%d %.2lf\n", i, f(op, i));
    return 0;
}