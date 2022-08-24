#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define mod 997
#define p 103
typedef long long LL;

struct phoneBook
{
    char name[25], num[12];
} b[110];
int n, nb, flag[1000][11];

int cmp(const void *a, const void *b)
{
    return strcmp(((struct phoneBook *)a)->name, ((struct phoneBook *)b)->name);
}

int Hash(char *s)
{
    int len = strlen(s), tot = 0, pp = 1;
    for (int i = 0; i < len; ++i)
    {
        tot = (tot + s[i] * pp % mod) % mod;
        pp = pp * p % mod;
    }
    return tot;
}

int find(int Name, int Num)
{
    for (int i = 1; i <= flag[Name][0]; ++i)
    {
        if (flag[Name][i] == Num)
            return 1;
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    struct phoneBook ls;
    int tmpName, tmpNum;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s %s", ls.name, ls.num);
        tmpName = Hash(ls.name);
        tmpNum = Hash(ls.num);
        if (!flag[tmpName][0])
        {
            b[nb++] = ls;
            flag[tmpName][++flag[tmpName][0]] = tmpNum;
        }
        else
        {
            if (!find(tmpName, tmpNum))
            {
                char tmpS[3] = "_";
                tmpS[1] = flag[tmpName][0] + '0';
                flag[tmpName][++flag[tmpName][0]] = tmpNum;
                strcat(ls.name, tmpS);
                b[nb++] = ls;
            }
        }
    }
    qsort(b, nb, sizeof(struct phoneBook), cmp);
    // puts("output:");
    for (int i = 0; i < nb; ++i)
        printf("%s %s\n", b[i].name, b[i].num);
    return 0;
}