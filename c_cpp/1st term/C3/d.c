#include <stdio.h>
#define max(a, b) (a > b ? a : b)
int n, a[100], m = -2147483648, ans = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i), m = max(m, a[i]);
    for (int i = 0; i < n; ++i) ans += m == a[i];
    printf("%d\n%d", m, ans);
    return 0;
}