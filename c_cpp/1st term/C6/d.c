#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
char a[105], b[105];
int main()
{
    gets(a), gets(b);
    if (strstr(a, b) != NULL) printf("YES %d\n", strstr(a, b) - a);
    else puts("NO");
    return 0;
}