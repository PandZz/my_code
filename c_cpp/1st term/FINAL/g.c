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
int a[10005], len, N, ans[100005], lenA;
const LL maxn = 1LL << 20;

void convert(LL x)
{
    len = 0;
    while (x)
    {
        a[++len] = x % N;
        x /= N;
    }
}

int check()
{
    int l = 1, r = len;
    while (l < r)
        if (a[l++] != a[r--]) return 0;
    return 1;
}

void print()
{
    if (N <= 10)
    {
        F(i, 1, lenA) printf("%d", ans[i]);
    }
    else
    {
        F(i, 1, lenA)
        {
            if (ans[i] < 10) printf("%d", ans[i]);
            else printf("%c", ans[i] - 10 + 'A');
        }
    }
    printf("\n");
}

int main()
{
    int ans1;
    while (~scanf("%d", &N))
    {
        ans1 = 0;
        for (LL i = 1; i <= maxn; ++i)
        {
            convert(i * i);
            if (check())
            {
                ++ans1;
                F(j, 1, len) ans[j] = a[j];
                lenA = len;
            }
        }
        printf("%d\n", ans1);
        print();
    }
    return 0;
}