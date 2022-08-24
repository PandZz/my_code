#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int t, a[11][11], b[11][11], c[11][11];
int main()
{
    scanf("%d", &t);
    F(i, 1, t)
        F(j, 1, t) scanf("%d", &a[i][j]);
    F(i, 1, t)
        F(j, 1, t) scanf("%d", &b[i][j]);
    F(i, 1, t)
        F(j, 1, t)
            F(k, 1, t) c[i][j] += a[i][k] * b[k][j];
    F(i, 1, t)
    {
        F(j, 1, t) printf("%d ", c[i][j]);
        putchar('\n');
    }
    return 0;
}