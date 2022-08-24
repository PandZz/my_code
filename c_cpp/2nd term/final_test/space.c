#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
struct data
{
    int st, ed;
}a[105], b[105];
int n, m;

void swap(struct data *p1, struct data *p2)
{
    struct data tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &a[i].st, &a[i].ed);
    for (int k = 1; k < n; ++k)
    {
        for (int i = 1; i <= n - k; ++i)
            if (a[i].st > a[i + 1].st) swap(a + i, a + i + 1);
    }
    /* for (int i = 1; i <= n; ++i)
        printf("%d %d\n", a[i].st, a[i].ed); */
    struct data tmp;
    int i = 1;
    while (i <= n)
    {
        tmp = a[i];
        while (a[i + 1].st == tmp.ed + 1) tmp.ed = a[++i].ed;
        b[++m] = tmp, ++i;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d %d\n", b[i].st, b[i].ed);
    return 0;
}