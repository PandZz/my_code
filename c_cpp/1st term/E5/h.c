#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int findHigh(int x)
{
    int pos = 0, ans;
    while (x)
    {
        if (x & 1) ans = pos;
        x >>= 1, ++pos;
    }
    return ans;
}

void print(int x)
{
    if (x == 0)
    {
        putchar('0');
        return ;
    }
    int pos = 0, flag = 0, high = findHigh(x);
    while (high >= 0)
    {
        if (x & (1 << high))
        {
            if (!flag)
            {
                flag = 1;
                printf("2(");
                print(high);
                printf(")");
            }
            else
            {
                putchar('+');
                printf("2(");
                print(high);
                printf(")");
            }
        }
        --high;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print(n);
    // while (~scanf("%d", &n)) printf("%d\n", findHigh(n));
    return 0;
}