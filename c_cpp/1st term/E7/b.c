#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int n, lenA, lenB;
char a[105], b[105];

int main()
{
    int len, ans = 0;
    scanf("%d", &n);
    F(i, 1, n)
    {
        ans = 0;
        scanf("%s%s", a, b);
        lenA = strlen(a), lenB = strlen(b);
        len = min(lenA, lenB);
        F(j, 0, len - 1) ans += a[j] != b[j];
        ans += max(lenA, lenB) - len;
        printf("%d\n", ans);
    }
    return 0;
}