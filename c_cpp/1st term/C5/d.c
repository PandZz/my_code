#include <stdio.h>
#define min(a, b) (a < b ? a : b)
int c[21][21];

int cal(int m, int n)
{
    if (c[m][n]) return c[m][n];
    return c[m][n] = cal(m - 1, n) + cal(m - 1, n - 1);
}

int main()
{
    int t, m, n;
    scanf("%d", &t);
    for (int i = 1; i <= 20; ++i) c[i][0] = c[i][i] = 1;
    while (t--)
    {
        scanf("%d%d", &m, &n);
        n = min(n, m - n);
        printf("%d\n", cal(m, n));
    }
    return 0;
}