#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct login
{
    int id, m, t;
    char name[20];
} a[205];
int n;

int cmp(const void *p1, const void *p2)
{
    if (((const struct login *)p1)->id == ((const struct login *)p2)->id)
        return ((const struct login *)p1)->m - ((const struct login *)p2)->m;
    return ((const struct login *)p1)->id - ((const struct login *)p2)->id;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %s %d %d", &a[i].id, a[i].name, &a[i].m, &a[i].t);
    qsort(a + 1, n, sizeof(struct login), cmp);
    int last_id = -1, last_m = -1, flag;
    for (int i = 1; i <= n;)
    {
        last_id = a[i].id, last_m = a[i].m, flag = 0;
        ++i;
        while (a[i].id == last_id)
        {
            if (a[i].m != last_m) flag = i;
            ++i;
        }
        if (flag) printf("%d %s\n", a[flag].id, a[flag].name);
    }
    return 0;
}