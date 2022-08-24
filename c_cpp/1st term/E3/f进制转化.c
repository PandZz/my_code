#include <stdio.h>
#include <string.h>
typedef long long LL;
char a[110];
int n, m, len;

void baseConvert(LL x)
{
    if (!x) return ;
    LL s = x % m;
    baseConvert(x / m);
    if (s < 10) printf("%lld", s);
    else printf("%c", s - 10 + 'A');
    return ;
}

int main()
{
    scanf("%s%lld%lld", a + 1, &n, &m);
    len = strlen(a + 1);
    LL s = 1, ls = 0;
    for (int i = len; i >= 1; --i)
    {
        if ('0' <= a[i] && a[i] <= '9') ls += s * (a[i] - '0');
        else ls += s * (a[i] - 'A' + 10);
        s *= n;
    }
    baseConvert(ls);
    return 0;
}