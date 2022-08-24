#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct node
{
    int num, cnt;
    struct node *l, *r;
} *head;
int n, ans_tot, ans_cnt = 1;
int path[10000];

struct node * make()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    memset(p, 0, sizeof(struct node));
    return p;
}

void insert_bst(struct node *p, int x)
{
    if (p->cnt == 0)
    {
        p->num = x;
        p->cnt = 1;
        return ;
    }
    ++ans_tot;
    if (x == p->num)
    {
        p->cnt++;
        ans_cnt = max(ans_cnt, p->cnt);
        return ;
    }
    if (x < p->num)
    {
        if (p->l == NULL) p->l = make();
        insert_bst(p->l, x);
    }
    else
    {
        if (p->r == NULL) p->r = make();
        insert_bst(p->r, x);
    }
}

void dfs(struct node *p, int path_n)
{
    if (p == NULL) return ;
    path[path_n] = p->num;
    if (p->cnt == ans_cnt)
    {
        for (int i = 1; i <= path_n; ++i)
            printf("%d ", path[i]);
        printf("\n");
        exit(0);
    }
    dfs(p->l, path_n + 1);
    dfs(p->r, path_n + 1);
}

int main()
{
    head = make();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        insert_bst(head, tmp);
    }
    printf("%d\n", ans_tot);
    dfs(head, 1);
    return 0;
}