#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
int main()
{
    double a, b, c = 0, d = 0;
    while (1)
    {
        scanf("%lf%lf", &a, &b);
        if (a < 0) break;
        c += a * b, d += b;
    }
    printf("%lf\n", c / d);
    return 0;
}