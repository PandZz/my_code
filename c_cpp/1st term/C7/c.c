#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int max(int x, int y) { return x > y ? x : y; }

int main()
{
    int n, id, op, s = 0;
    scanf("%d", &n);
    F(i, 1, n)
    {
        scanf("%d%d", &id, &op);
        switch (op)
        {
            case 0: s += id % 10; break;
            case 1: break;
            case 2: s = max(s - 2, 0); break;
        }
    }
    // printf("%d\n", s);
    if (s >= 37) printf("%d\n", s);
    else puts("See you next year !");
    return 0;
}