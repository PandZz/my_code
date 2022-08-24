#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define N 10005
typedef long long LL;
char s[N];

char* unzip(char *);

int main()
{
    scanf("%s", s);
    char *ans = unzip(s);
    printf("%s", ans);
    free(ans);
    return 0;
}

char* unzip(char *s)
{
    char *ans = (char *)malloc(sizeof(char) * N), lsAlpha[] = "0";
    memset(ans, 0, sizeof(char) * N);
    int i = 0, j = 0, len = strlen(s), times = 0, tmp, size;
    while (i < len)
    {
        if (isalpha(s[i]))
        {
            lsAlpha[0] = s[i++];
            strcat(ans, lsAlpha);
            continue;
        }
        if (isdigit(s[i]))
        {
            times = 0;
            while (isdigit(s[i]))
            {
                times = times * 10 + s[i] - '0';
                ++i;
            }
            tmp = 1, j = i + 1, size = -1;
            while (tmp)
            {
                if (s[j] == '(') ++tmp;
                else if (s[j] == ')') --tmp;
                ++size, ++j;
            }
            char *subS = (char *)malloc(sizeof(char) * (size + 5)), *subAns;
            memset(subS, 0, sizeof(char) * (size + 5));
            strncpy(subS, s + i + 1, size);
            subAns = unzip(subS);
            F(k, 1, times) strcat(ans, subAns);
            free(subS), free(subAns);
            i = j;
        }
    }
    return ans;
}
