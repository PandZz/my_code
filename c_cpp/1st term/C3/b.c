#include <stdio.h>
int main()
{
    int n, x;
    while (~scanf("%d%d", &n, &x))
    {
        printf("%d %d %d\n", x & 1, x > 0, x == n);
    }
    return 0;
}