#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define N 100
typedef long long LL;
typedef struct edge
{
    int adjvex;
    int weight;
    struct edge *next;
}Elink;
typedef struct ver
{
    int vertex;
    Elink *link, *last;
}Vlink;

Vlink G[N];

void connect(int v1, int v2, int w)
{
    Elink *p = (Elink *)malloc(sizeof(Elink));
    p->adjvex = v2, p->weight = w, p->next = NULL;
    if (!G[v1].link)
        G[v1].link = G[v1].last = p;
    else
    {
        (G[v1].last)->next = p;
        G[v1].last = p;
    }
}

struct data
{
    int len, path[N];
} a[N * 10];
int cmp(const void *p1, const void *p2)
{
    struct data *q1 = (struct data *)p1, *q2 = (struct data *)p2;
    for (int i = 0; i < min(q1->len, q2->len); ++i)
    {
        if (q1->path[i] < q2->path[i]) return -1;
        if (q1->path[i] > q2->path[i]) return 1;
    }
    return q1->len - q2->len;
}

int n, e, vis[N], len, ansN, path[N];
void dfs(int x)
{
    if (x == n - 1)
    {
        a[++ansN].len = len;
        memcpy(a[ansN].path, path, sizeof(int) * len);
        // for (int i = 0; i < len; ++i) printf("%d ", a[ansN].path[i]);
        // puts("");
        return ;
    }
    for (Elink *p = G[x].link; p; p = p->next)
    {
        if (!vis[p->adjvex])
        {
            vis[p->adjvex] = 1, path[len++] = p->weight;
            dfs(p->adjvex);
            vis[p->adjvex] = 0, --len;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &e);
    for (int i = 1; i <= e; ++i)
    {
        int w, a, b;
        scanf("%d%d%d", &w, &a, &b);
        // printf("%d %d %d\n", w, a, b);
        connect(a, b, w), connect(b, a, w);
    }
    vis[0] = 1;
    dfs(0);
    qsort(a + 1, ansN, sizeof(struct data), cmp);
    for (int i = 1; i <= ansN; ++i)
    {
        for (int j = 0; j < a[i].len; ++j) printf("%d ", a[i].path[j]);
        puts("");
    }
    return 0;
}