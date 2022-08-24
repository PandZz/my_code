#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct code
{
    char ch;
    struct code *pre, *nxt;
} base;

char s[50], keys[150];
int flag[150];

void del(struct code *p)
{
    p->pre->nxt = p->nxt;
    p->nxt->pre = p->pre;
}

int main()
{
    FILE *fr, *fw;
    int len = strlen(s), n = 1;
    struct code *tmpCodeP, *CodeP;
    char p, c;
    fr = fopen("in.txt", "r"), fw = fopen("in_crpyt.txt", "w");
    memset(flag, 0, sizeof(flag)), memset(keys, 0, sizeof(keys));
    fgets(s, 50, stdin);
    len = strlen(s);
    base.ch = s[0], base.nxt = base.pre = &base, flag[s[0]] = 1;
    CodeP = &base;
    for (int i = 1; i < len; ++i)
    {
        if (!flag[s[i]] && 32 <= s[i] && s[i] <= 126)
        {
            n++;
            flag[s[i]] = 1;
            tmpCodeP = malloc(sizeof(struct code));
            tmpCodeP->ch = s[i], tmpCodeP->nxt = CodeP->nxt, tmpCodeP->pre = CodeP;
            CodeP->nxt->pre = tmpCodeP, CodeP->nxt = tmpCodeP;
            CodeP = CodeP->nxt;
        }
    }
    for (int i = 32; i <= 126; ++i)
    {
        if (!flag[i])
        {
            n++;
            flag[i] = 1;
            tmpCodeP = malloc(sizeof(struct code));
            tmpCodeP->ch = i, tmpCodeP->nxt = CodeP->nxt, tmpCodeP->pre = CodeP;
            CodeP->nxt->pre = tmpCodeP, CodeP->nxt = tmpCodeP;
            CodeP = CodeP->nxt;
        }
    }
    /*
        printf("%c", base.ch);
        for (CodeP = base.nxt; CodeP != &base; CodeP = CodeP->nxt)
            printf("%c", CodeP->ch);
    */
    CodeP = &base;
    for (int i = 1; i < n; ++i)
    {
        p = CodeP->ch, CodeP = CodeP->nxt;
        del(CodeP->pre);
        for (int j = 1; j < p; ++j)
            CodeP = CodeP->nxt;
        c = CodeP->ch;
        keys[p] = c;
    }
    keys[CodeP->ch] = s[0];
    /*
        for (int i = 32; i <= 126; ++i)
            printf("%c", keys[i]);
    */
    while ((c = fgetc(fr)) != EOF)
    {
        if (32 <= c && c <= 126)
            c = keys[c];
        fputc(c, fw);
    }
    fclose(fr), fclose(fw);
    return 0;
}