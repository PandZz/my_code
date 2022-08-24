#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define swap(a, b) (a ^= b, b ^= a, a ^= b)
typedef long long LL;

int a[2005];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    F(i, 1, n) scanf("%d", a + i);
    int flag = 0;
    F(i, 1, n)
    {
        flag = 0;
        F(j, 1, n - i)
        {
            if (a[j] < a[j + 1]) swap(a[j], a[j + 1]), flag = 1;
        }
        if (!flag) break;
    }
    F(i, 1, k)
    {
        scanf("%d", &flag);
        printf("%d\n", a[flag]);
    }
    return 0;
}