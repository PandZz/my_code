#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define N 400
typedef long long LL;

int statN = 0;
char station[N][20];
int w[N][N], line[N][N], isTrans[N], dis[N], path[N][N], pathN[N], vis[N];

int search_id(char *);
void Dijkstra(int, int);
void print(int, int);

int main()
{
    FILE *fp = fopen("bgstations.txt", "r");
    memset(w, 2, sizeof(w));
    // printf("%d\n", w[0][0]);
    int m, n, l, last, now, st, ed;
    char str[100];
    fscanf(fp, "%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        fscanf(fp, "%d%d", &l, &m);
        last = -1;
        for (int j = 1; j <= m; ++j)
        {
            fscanf(fp, " %s", str);
            now = search_id(str);
            // printf("%s %d\n", str, now);
            if (last >= 0) w[last][now] = w[now][last] = 1, line[last][now] = line[now][last] = l;
            last = now, fscanf(fp, "%d", &isTrans[now]);
        }
    }
    scanf(" %s", str), st = search_id(str);
    scanf("%s", str), ed = search_id(str);
    // st = search_id("西土城");
    // ed = search_id("环球度假区");
    // printf("%d %d\n", st, ed);
    Dijkstra(st, ed);
    // printf("%d\n", dis[ed]);
    print(st, ed);
    return 0;
}

int search_id(char *str)
{
    for (int i = 0; i < statN; ++i)
        if (strcmp(station[i], str) == 0) return i;
    strcpy(station[statN], str);
    return statN++;
}

void Dijkstra(int st, int ed)
{
    for (int i = 0; i < statN; ++i)
    {
        w[i][i] = 0;
        dis[i] = w[st][i];
        path[i][pathN[i]++] = st;
    }
    vis[st] = 1;
    for (int i = 1; i < statN; ++i)
    {
        int k = -1;
        for (int j = 0; j < statN; ++j)
            if (!vis[j] && (k == -1 || dis[j] < dis[k])) k = j;
        vis[k] = 1, path[k][pathN[k]++] = k;
        if (k == ed) return ;
        for (int l = 0; l < statN; ++l)
        {
            if (!vis[l] && dis[k] + w[k][l] < dis[l])
            {
                dis[l] = dis[k] + w[k][l];
                pathN[l] = pathN[k];
                for (int p = 0; p < pathN[k]; ++p) path[l][p] = path[k][p];
            }
        }
    }
}

void print(int st, int ed)
{
    int lastTrans = st, x, y, lastLine = line[st][path[ed][1]];
    printf("%s-", station[st]);
    for (int i = 1; i < pathN[ed] - 1; ++i)
    {
        x = path[ed][i], y = path[ed][i + 1];
        if (line[x][y] != lastLine)
        {
            printf("%d(%d)-%s-", lastLine, dis[x] - dis[lastTrans], station[x]);
            lastTrans = x, lastLine = line[x][y];
        }
    }
    printf("%d(%d)-%s\n", lastLine, dis[ed] - dis[lastTrans], station[ed]);
}