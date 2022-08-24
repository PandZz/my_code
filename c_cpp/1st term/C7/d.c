#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
char s[205], t[205];

void rev(char* l, char* r)
{
    int tmp;
    while (l < r)
    {
        tmp = *l;
        *l = *r, *r = tmp;
        ++l, --r;
    }
    return ;
}

int check(char* ch, int len)
{
    int l = 0, r = len - 1;
    while (l < r)
    {
        if (ch[l] != ch[r]) return 0;
        ++l, --r;
    }
    return 1;
}

int main()
{
    scanf("%s %s", s, t);
    char *p;
    int lenT = strlen(t), x = 0, lenS = strlen(s);
    if (check(t, lenT))
    {
        puts(s);
        return 0;
    }
    while (x < lenS && (p = strstr(s + x, t)) != NULL)
    {
        rev(p, p + lenT - 1);
        x += p - s + lenT;
    }
    puts(s);
    return 0;
}