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
#define N 1005

int tmpLen, maxLen, minLen = 10005;
char tmp[N], maxAns[N], minAns[N];

int main()
{
    while (gets(tmp) != NULL)
    {
        tmpLen = strlen(tmp);
        if (tmpLen < minLen) { minLen = tmpLen; strcpy(minAns, tmp); }
        if (tmpLen > maxLen) { maxLen = tmpLen; strcpy(maxAns, tmp); }
    }
    printf("%d\n%s\n", minLen, minAns);
    printf("%d\n%s\n", maxLen, maxAns);
    return 0;
}