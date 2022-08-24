#include <stdio.h>
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
int Min[3] = {101, 101, 101}, Max[3], s[3];
double a[3];
int main()
{
    int n, score;
    char c, ans;
    double ls = -1;
    scanf("%d", &n);
    while (n--)
    {
        scanf(" %c%d", &c, &score);
        ++s[c - 'A'];
        a[c - 'A'] += score;
        Min[c - 'A'] = min(Min[c - 'A'], score);
        Max[c - 'A'] = max(Max[c - 'A'], score);
    }
    for (int i = 0; i < 3; ++i)
    {
        a[i] /= s[i];
        if (a[i] > ls)
        {
            ans = i + 'A';
            ls = a[i];
        }
    }
    printf("%c\n", ans);
    for (int i = 0; i < 3; ++i) printf("%d %d\n", Max[i], Min[i]);
    return 0;
}