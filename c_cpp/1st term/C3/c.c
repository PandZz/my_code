#include <stdio.h>
#define min(a, b) (a < b ? a : b)
int main()
{
    int n;
    char a, b;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%c%c", &a, &b);
        if (i < n) printf("%c ", min(a, b));
        else printf("%c", min(a, b));
    }
    return 0;
}