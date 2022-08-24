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

int n, m, a[103][103], b[103][103];

int sum(int x, int y)
{
    int s = 0;
    F(i, -1, 1)
        F(j, -1, 1) s += a[x + i][y + j];
    return s;
}

int main()
{
    scanf("%d%d", &m, &n);
    F(i, 1, m)
        F(j, 1, n) scanf("%d", &a[i][j]);
    double tmp;
    F(i, 1, m)
        F(j, 1, n)
        {
            tmp = sum(i, j);
            tmp /= (1 + (i > 1) + (i < m)) * (1 + (j > 1) + (j < n));
            b[i][j] = tmp;
            if ((int)(tmp * 2) > (int)tmp * 2) ++b[i][j];
        }
    F(i, 1, m)
    {
        F(j, 1, n) printf("%3d ", b[i][j]);
        puts("");
    }
    return 0;
}