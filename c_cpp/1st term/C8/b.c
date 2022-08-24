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
char a[1000];
int main()
{
    scanf("%s", a);
    char *p = strstr(a, "EDGnb");
    if (p != NULL) printf("%d", p - a + 1);
    else puts("-1");
    return 0;
}