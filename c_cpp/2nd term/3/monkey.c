#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
int n, m, q;

struct monkey
{
    int id;
    struct monkey *next;
} base;

int main()
{
    struct monkey *p = &base;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i < n; ++i)
    {
        p->id = i;
        p->next = malloc(sizeof(struct monkey));
        p = p->next;
    }
    p->id = n, p->next = &base;
    while (p->id != q)
        p = p->next;
    for (int i = 1; i < n; ++i)
    {
        for (int i = 2; i < m; ++i)
            p = p->next;
        p->next = p->next->next;
        p = p->next;
    }
    printf("%d\n", p->id);
    return 0;
}