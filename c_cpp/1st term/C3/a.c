#include <stdio.h>
int n;
int a[100], b[100];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    for (int i = 0; i < n; ++i) printf("%d", a[i] ^ b[i]);
    putchar('\n');
    for (int i = 0; i < n; ++i) printf("%d", a[i] | b[i]);
    putchar('\n');
    for (int i = 0; i < n; ++i) printf("%d", a[i] & b[i]);
    return 0;
}