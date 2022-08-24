#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define N 205
typedef long long LL;

struct data
{
    int id, val;
} a[N];

int tree[N][5], fa[N], n, root;
int ans[N], ansN;

int findR(int x)
{
    return fa[x] ? findR(fa[x]) : x;
}

int q[N * 10], s, t = -1;
void bfs()
{
    int R;
    q[++t] = root;
    while (t - s >= 0)
    {
        R = q[s++];
        if (R < 100) ans[++ansN] = R;
        for (int i = 1; i <= tree[R][0]; ++i) q[++t] = tree[R][i];
    }
}

int cmp(struct data *p1, struct data *p2)
{
    if (p1->val == p2->val) return p1->id - p2->id;
    return p2->val - p1->val;
}

int main()
{
    int R, tmp;
    while (~scanf("%d", &R) && R != -1)
    {
        while (~scanf("%d", &tmp) && tmp != -1)
        {
            tree[R][++tree[R][0]] = tmp;
            fa[tmp] = R;
        }
    }
    while (~scanf("%d%d", &R, &tmp))
    {
        a[++n].id = R;
        a[n].val = tmp;
    }
    root = findR(R);
    bfs();
    qsort(a + 1, n, sizeof(struct data), cmp);
    // for (int i = 1; i <= n; ++i)
    //     printf("%d %d\n", a[i].id, a[i].val);
    for (int i = 1; i <= ansN; ++i)
        printf("%d->%d\n", a[i].id, ans[i]);
    return 0;
}