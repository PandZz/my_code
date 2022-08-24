#include <stdio.h>
#include <string.h>
int n;
char a[(1 << 20) + 1], ans[(1 << 20) + 1];

void solve(int pos, int x)
{
    for (int i = pos + 3; i >= pos; --i)
    {
        ans[i] = !(x & 1) + '0';
        x >>= 1;
    }
}

int main()
{
    scanf("%d%s", &n, a + 1);
    for (int i = 1; i <= n / 4; ++i)
    {
        if ('0' <= a[i] && a[i] <= '9') solve((i - 1) * 4 + 1, a[i] - '0');
        else solve((i - 1) * 4 + 1, a[i] - 'A' + 10);
    }
    ++ans[n];
    for (int i = n; i >= 1; --i)
        if (ans[i] > '1')
        {
            ans[i] = '0';
            ++ans[i - 1];
        }
    ans[n + 1] = 0;
    printf("%s", ans + 1);
    return 0;
}