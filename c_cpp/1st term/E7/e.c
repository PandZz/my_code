#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
#define N 10000

int n, c[N + 5];

int main()
{
    int a;
    scanf("%d", &n);
    F(i, 1, n) scanf("%d", &a), c[a]++;
    F(i, 1, N)
        if (c[i]) printf("%d:%d\n", i, c[i]);
    return 0;
}