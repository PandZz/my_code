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