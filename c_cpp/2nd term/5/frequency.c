#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define lower(a) ('a' <= a && a <= 'z' ? a : a - 'A' + 'a')
typedef long long LL;

struct node
{
    char *str;
    int cnt, lson, rson;
} tree[1000];
char s[200], n = 1;

void insert(int k, int st, int edd)
{
    if (!tree[k].cnt)
    {
        tree[k].str = malloc(sizeof(char) * (edd - st + 1));
        strncpy(tree[k].str, s + st, edd - st);
        tree[k].str[edd - st] = '\0';
        tree[k].cnt++;
        return ;
    }
    int cmp = strncmp(s + st, tree[k].str, max(edd - st, strlen(tree[k].str)));
    if (cmp < 0)
    {
        if (!tree[k].lson)
            tree[k].lson = ++n;
        insert(tree[k].lson, st, edd);
    }
    else if (cmp == 0)
        ++tree[k].cnt;
    else
    {
        if (!tree[k].rson)
            tree[k].rson = ++n;
        insert(tree[k].rson, st, edd);
    }
}

void dfs(int p)
{
    if (!tree[p].cnt) return;
    dfs(tree[p].lson);
    printf("%s %d\n", tree[p].str, tree[p].cnt);
    dfs(tree[p].rson);
}

int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");
    while (fgets(s, 200, fp) != NULL)
    {
        int len, i, j;
        len = strlen(s);
        for (i = 0; i < len; ++i)
            if (isalpha(s[i])) s[i] = lower(s[i]);
        i = 0;
        while (i < len)
        {
            if (!isalpha(s[i])) { ++i; continue; }
            j = i;
            while (isalpha(s[j]) && j <= len) ++j;
            // for (int k = i; k < j; ++k) printf("%c", s[k]);
            // puts("");
            insert(1, i, j);
            i = j + 1;
        }
    }
    int p = 1, i = 1;
    for (; tree[p].cnt && i <= 2; p = tree[p].rson, i++)
        printf("%s ", tree[p].str);
    if (tree[p].cnt) printf("%s", tree[p].str);
    puts("");
    // printf("%d\n", n);
    // for (int i = 1; i <= n; ++i)
    //     printf("str=%s cnt=%d lson=%d rson=%d\n", tree[i].str, tree[i].cnt, tree[i].lson, tree[i].rson);
    dfs(1);
    return 0;
}