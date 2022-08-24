#include <stdio.h>
int main()
{
    int x;
    scanf("%x", &x);
    int ls = (1 << 5) - 1;
    printf("add $%d,$%d,$%d\n", (x >> 11) & ls, (x >> 21) & ls, (x >> 16) & ls);
    return 0;
}