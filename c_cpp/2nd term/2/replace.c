#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define f(c) (c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c)
typedef long long LL;
char s[200], t[200], ls[200];
int sn, tn, n;
int main()
{
    scanf("%s %s", s, t);
    sn = strlen(s), tn = strlen(t);
    for (int i = 0; i < sn; ++i)
        s[i] = f(s[i]);
    FILE *fr, *fw;
    fr = fopen("filein.txt", "r");
    fw = fopen("fileout.txt", "w");
    while (fgets(ls, 200, fr) != NULL)
    {
        n = strlen(ls);
        for (int i = 0; i < n; ++i)
        {
            if (f(ls[i]) != s[0])
            {
                fputc(ls[i], fw);
                continue;
            }
            int j;
            for (j = 0; f(ls[i + j]) == s[j] && j < sn; ++j)
                ;
            if (j == sn)
            {
                fputs(t, fw);
                i += j - 1;
            }
            else
                fputc(ls[i], fw);
        }
    }
    fclose(fr);
    fclose(fw);
    return 0;
}