#include <stdio.h>
#include <string.h>
int len;
char ch[1000005];

int check(char ch)
{
    if ('0' <= ch && ch <= '9') return 1;
    if ('a' <= ch && ch <= 'z') return 1;
    if ('A' <= ch && ch <= 'Z') return 1;
    return 0;
}

int main()
{
    gets(ch);
    len = strlen(ch);
    int st, en, f = 0, l = 0, ansSt = -1, ansEn = -1, cnt = 0, ansCnt, ansCh = 0, n;
    for (int i = 0; i < len; ++i)
    {
        if (!f)
        {
            if (check(ch[i])) f = 1, st = i, n = 1;
        }
        else
        {
            if (check(ch[i])) ++n;
            if (ch[i] == '.' || ch[i] == '!' || ch[i] == '?')
            {
                en = i;
                f = 0;
                ++cnt;
                if (n > l)
                {
                    ansCnt = cnt;
                    l = n;
                    ansSt = st, ansEn = en;
                }
            }
        }
    }
    printf("%d\n%d\n", ansCnt, l);
    // printf("ch[%d] = %c ch[%d] = %c\n", ansSt, ch[ansSt], ansEn, ch[ansEn]);
    for (int i = ansSt; i <= ansEn; ++i) printf("%c", ch[i]);
    return 0;
}