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
#define N 1005

int n, a[N], b[N], r[N], nb, nr;
char c[N];

int cmp(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int flag = 0;
        scanf("%d", &n);
        F(i, 0, n - 1) scanf("%d", a + i);
        scanf("%s", c);
        F(i, 0, n - 1)
        nb = nr = 0;
        F(i, 0, n - 1)
        {
            if (c[i] == 'B') b[++nb] = a[i];
            else r[++nr] = a[i];
        }
        qsort(b + 1, nb, sizeof(int), cmp);
        qsort(r + 1, nr, sizeof(int), cmp);
        F(i, 1, nb)
            if (b[i] < i) { flag = -1; break; }
        if (!flag)
        {
            F(i, 1, nr)
                if (r[i] > i + nb) { flag = -1; break; }
        }
        if (flag == -1) puts("NO");
        else puts("YES");
    }
    return 0;
}