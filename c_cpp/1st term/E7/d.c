#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
char a[101][105], *lst[101];
int n, m;
int main()
{
    scanf("%d%d ", &n, &m);
    F(i, 1, n) gets(a[i]), lst[i] = a[i];
    int l1, l2;
    char *tmp;
    F(i, 1, m)
    {
        scanf("%d%d", &l1, &l2);
        tmp = lst[l1];
        lst[l1] = lst[l2];
        lst[l2] = tmp;
    }
    F(i, 1, n) puts(lst[i]);
    return 0;
}