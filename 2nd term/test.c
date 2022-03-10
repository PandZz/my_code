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
int x[] = {0, 1, 2, 3, 4, 5}, *p1;
int main()
{
    printf("%d\n", (p1 = x + 2, *(p1++)));
    return 0;
}