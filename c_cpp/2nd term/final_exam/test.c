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
    int a, b;
} *p;

int main()
{
    p->a = p->b = 100;
    printf("%d %d\n", p->a, *p.a);
    return 0;
}