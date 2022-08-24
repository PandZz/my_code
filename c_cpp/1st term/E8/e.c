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
#define N 100005

int n, m;
int d[N], id[N];

int main()
{
    scanf("%d%d", &n, &m);
    F(i, 0, n - 1) scanf("%d%d", d + i, id + i);
    int s, x, step = 0;
    F(i, 1, m)
    {
        scanf("%d%d", &s, &x);
        s ^= d[step];
        if (!s) step = (step - x + n) % n;
        else step = (step + x) % n;
    }
    printf("%d\n", id[step]);
    return 0;
}