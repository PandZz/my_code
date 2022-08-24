#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define N 10005
#define maxV (1 << 30)
typedef long long LL;
typedef struct edge
{
    int adjvex, weight, id;
    struct edge *next;
}Elink;
typedef struct ver
{
    int vertex;
    Elink *link, *last;
}Vlink;

Vlink G[N];

void connect(int v1, int v2, int w, int id)
{
    Elink *p = (Elink *)malloc(sizeof(Elink));
    p->adjvex = v2, p->weight = w, p->id = id, p->next = NULL;
    if (!G[v1].link)
        G[v1].link = G[v1].last = p;
    else
    {
        (G[v1].last)->next = p;
        G[v1].last = p;
    }
}
int n, m, ans, id[N], idN;

Elink * lowcost[N];
void prim()
{
    int i, j, k;
    Elink minE = {0, 0, 0, NULL}, maxE = {0, maxV, 0, NULL}, minCost;
    for (Elink *p = G[0].link; p; p = p->next)
        lowcost[p->adjvex] = p;
    lowcost[0] = &minE;
    for (int i = 1; i < n; ++i)
    {
        if (!lowcost[i])
            lowcost[i] = &maxE;
    }
    for (i = 1; i < n; ++i)
    {
        j = 1;
        minCost = maxE;
        while (j < n)
        {
            if (lowcost[j]->weight > 0 && lowcost[j]->weight < minCost.weight)
            {
                minCost = *lowcost[j];
                k = j;
            }
            ++j;
        }
        ans += minCost.weight, id[++idN] = minCost.id;
        lowcost[k] = &minE;
        for (Elink *p = G[k].link; p; p = p->next)
            if (p->weight < lowcost[p->adjvex]->weight) lowcost[p->adjvex] = p; 
    }
}

int cmp(const void *p1, const void *p2)
{
    return *((int*)p1) - *((int*)p2);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int id, a, b, w;
        scanf("%d%d%d%d", &id, &a, &b, &w);
        connect(a, b, w, id), connect(b, a, w, id);
    }
    prim();
    qsort(id + 1, idN, 4, cmp);
    printf("%d\n", ans);
    for (int i = 1; i <= idN; ++i) printf("%d ", id[i]);
    return 0;
}