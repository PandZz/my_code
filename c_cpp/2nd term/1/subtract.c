#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

char a[100], b[100], ans[100];
void reverse(char *);
void clear(char *);
void cal(char *, char *);
int compare(char *, char *);

int main()
{
    scanf("%s%s", a, b);
    reverse(a), reverse(b);
    clear(a), clear(b);
    switch (compare(a, b))
    {
    case 1:
        cal(a, b);
        break;
    case -1:
        cal(b, a);
        putchar('-');
        break;
    case 0:
        puts("0");
        return 0;
    }
    reverse(ans);
    printf("%s\n", ans);
    return 0;
}

void reverse(char *s)
{
    char c;
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void clear(char *s)
{
    for (int i = strlen(s) - 1; i >= 0; --i)
    {
        if (s[i] != '0')
            return;
        else
            s[i] = '\0';
    }
}

int compare(char *a, char *b)
{
    int la = strlen(a), lb = strlen(b);
    if (la > lb)
        return 1;
    if (la < lb)
        return -1;
    for (int i = la - 1; i >= 0; --i)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}

void cal(char *a, char *b)
{
    int la = strlen(a), lb = strlen(b);
    for (int i = lb; i < la; ++i)
        b[i] = '0';
    for (int i = 0; i < la; ++i)
    {
        if (a[i] < b[i])
        {
            a[i] += 10;
            a[i + 1]--;
        }
        ans[i] += a[i] - b[i] + '0';
    }
    clear(ans);
}