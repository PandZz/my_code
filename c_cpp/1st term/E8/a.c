#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int main()
{
    double R;
    int op, r;
    scanf("%lf", &R);
    while (~scanf("%d%d", &op, &r))
    {
        if (!op) R += r;
        else R = R * r / (R + r);
    }
    printf("%.2lf\n", R);
    return 0;
}