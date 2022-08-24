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
char s[1005], ans[30];
int cnt[200], len;

double P(char c) { return (double)cnt[c] / len; }

double I(char c)
{
    return -log(P(c)) / log(2);
}

int cmp(const void *p1, const void *p2)
{
    if (I(*(char *)p1) < I(*(char *)p2)) return -1;
    if (I(*(char *)p1) > I(*(char *)p2)) return 1;
    else return *(char *)p1 - *(char *)p2;
}

int main()
{
    scanf("%s", s);
    len = strlen(s);
    double H = 0;
    F(i, 0, len - 1) cnt[s[i]]++;
    F(i, 0, 25) H += I(i + 'a') * P(i + 'a');
    printf("%.2lf\n", H);
    F(i, 0, 25) ans[i] = i + 'a';
    qsort(ans, 26, sizeof(char), cmp);
    F(i, 0, 9) printf("%c:%.2lf\n", ans[i], I(ans[i]));
    return 0;
}