#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int a[105][105], n, k, b[105][105];

int count(int x, int y)
{
    int s = 0;
    F(i, -1, 1)
        F(j, -1, 1) s += a[x + i][y + j];
    return s - a[x][y];
}

void cpy()
{
    F(i, 1, n)
        F(j, 1, n) a[i][j] = b[i][j];
    return ;
}

int main()
{
    scanf("%d%d", &n, &k);
    F(i, 1, n)
        F(j, 1, n) scanf("%d", &a[i][j]);
    int ls;
    F(m, 1, k)
    {
        F(i, 1, n)
            F(j, 1, n)
            {
                ls = count(i, j);
                if (a[i][j]) b[i][j] = ((ls == 2 || ls == 3) ? 1 : 0);
                else b[i][j] = (ls == 3 ? 1 : 0);
            }
        cpy();
    }
    F(i, 1, n)
    {
        F(j, 1, n) printf("%d ", a[i][j]);
        putchar('\n');
    }
    return 0;
}