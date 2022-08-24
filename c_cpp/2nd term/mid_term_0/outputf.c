#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
char s[200], t[200];
int len_s, len_t;

int getNum(char *p1, char *p2)
{
    int n = 0;
    while (p2 - p1 > 0)
    {
        n = n * 10 + *p1 - '0';
        p1++;
    }
    return n;
}

int main()
{
    gets(t), gets(s);
    len_s = strlen(s), len_t = strlen(t);
    int f, i, m, n;
    if (t[1] == '-') f = 1, i = 2;
    else f = 0, i = 1;
    int j = i;
    while (isdigit(t[j])) ++j;
    m = getNum(t + i, t + j);
    i = j + 1, j = i;
    while (isdigit(t[j])) ++j;
    n = getNum(t + i, t + j);
    // printf("%d %d %d\n", f, m, n);
    if (m <= len_s) s[m] = '\0', len_s = m;
    if (f)
    {
        if (n > len_s)
            for (int i = 1; i <= n - len_s; ++i) printf("#");
        printf("%s", s);
    }
    else
    {
        printf("%s", s);
        if (n > len_s)
            for (int i = 1; i <= n - len_s; ++i) printf("#");
    }
    return 0;
}