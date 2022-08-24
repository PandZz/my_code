#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct data
{
    char funcName[25];
    char func[10][25];
    int funcN;
} ans[105];
int n, top = -1, s[200];

int get_func_id(char * str)
{
    for (int i = 1; i <= n; ++i)
        if (strcmp(ans[i].funcName, str) == 0) return i;
    ++n;
    strcpy(ans[n].funcName, str);
    return n;
}

void insert_func(int id, char * str)
{
    for (int i = 1; i <= ans[id].funcN; ++i)
        if (strcmp(ans[id].func[i], str) == 0) return ;
    ans[id].funcN++;
    strcpy(ans[id].func[ans[id].funcN], str);
}

int main()
{
    int op;
    char func[25];
    scanf("%d %s", &op, func);
    s[++top] = get_func_id(func);
    // printf("%d %s\n", op, func);
    while (top > -1)
    {
        scanf("%d", &op);
        // printf("%d\n", op);
        if (op == 0) --top;
        else
        {
            scanf(" %s", func);
            // printf(" %s\n", func);
            insert_func(s[top], func);
            s[++top] = get_func_id(func);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i].funcN)
        {
            printf("%s:", ans[i].funcName);
            for (int j = 1; j < ans[i].funcN; ++j) printf("%s,", ans[i].func[j]);
            printf("%s\n", ans[i].func[ans[i].funcN]);
        }
    }
    return 0;
}