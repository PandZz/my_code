#include <stdio.h>

void solve(int x, int cnt)
{
    if (cnt == 30){ printf("%d", x & 1); return ; }
    solve(x >> 1, cnt + 1);
    printf("%d", x & 1);
    return ;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n >= 0){ putchar('0'); solve(n, 0);}
        else{ putchar('1'); solve(-n, 0); }
        putchar('\n');
    }
    return 0;
}