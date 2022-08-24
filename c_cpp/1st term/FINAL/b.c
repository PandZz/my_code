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
    LL x;
    scanf("%lld", &x);
    F(i, 0, 15) x ^= 1LL << i;
    printf("%lld\n", x);
    return 0;
}