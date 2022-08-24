#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int a[30][30], b[30], flag[30], s[30], cnt[30];
int main()
{
    int n, m;
    char x, y;
    scanf("%d%d", &n, &m);
    // printf("%d %d\n", n, m);
    F(i, 1, m)
    {
        scanf("\n%c %c", &x, &y);
        // printf("%c %c\n", x, y);
        if (x != y) a[x - 'A'][y - 'A'] = a[y - 'A'][x - 'A'] = 1;
    }
    F(i, 0, n - 1)
        F(j, 0, n - 1) b[i] += a[i][j];
    F(i, 0, n - 1)
        F(j, 0, n - 1)
            if (a[i][j]) s[i] += b[j], ++cnt[i];
    int flag = 0;
    F(i, 0, n - 1)
        if (b[i] * cnt[i] < s[i]) printf("%c ", 'A' + i), flag = 1;
    if (!flag) puts("Not Found");
    return 0;
}