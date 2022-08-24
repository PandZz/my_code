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
int main()
{
    int n, m;
    scanf("%d", &n);
    m = n - 1;
    F(i, 1, n)
    {
        F(j, 1, m) printf(" ");
        F(j, 1, i - 1) printf("* ");
        printf("*\n");
        m--;
    }
    return 0;
}