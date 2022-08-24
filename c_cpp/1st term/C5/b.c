#include <stdio.h>
int f[25] = {0, 1, 1, 1};
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= n; ++i) f[i] = f[i - 1] + f[i - 3];
    printf("%d\n", f[n]);
    return 0;
}