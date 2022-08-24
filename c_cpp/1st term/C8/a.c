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

int check(int x, int k)
{
    while (x)
    {
        if (x % 10 == k) return 1;
        x /= 10;
    }
    return 0;
}

int main()
{
    int k;
    scanf("%d", &k);
    F(i, 1, 99)
    {
        if (i % k == 0 || check(i, k)) continue;
        printf("%d ", i);
    }
    return 0;
}