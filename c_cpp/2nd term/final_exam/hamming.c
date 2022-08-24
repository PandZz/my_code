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
    char str[20];
    int dis;
} a[20];
int n;

int cmp(const void *p1, const void *p2)
{
    if (((struct data *)p1)->dis == ((struct data *)p2)->dis)
        return strcmp(((struct data *)p1)->str, ((struct data *)p2)->str);
    return ((struct data *)p1)->dis - ((struct data *)p2)->dis;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%s", a[i].str);
    int len = strlen(a[1].str);
    for (int i = 2; i <= n; ++i)
    {
        a[i].dis = 0;
        for (int j = 0; j < len; ++j)
            if (a[1].str[j] != a[i].str[j]) a[i].dis++;
    }
    qsort(a + 2, n - 1, sizeof(struct data), cmp);
    for (int i = 2; i <= n; ++i)
        printf("%s %s %d\n", a[1].str, a[i].str, a[i].dis);
    return 0;
}