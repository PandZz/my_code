#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct func
{
    int op, pos, len;
    char *s;
} stack[500];
int top = -1;
char str[550];

void insert(int pos, char s[])
{
    int len_s = strlen(s), len_str = strlen(str);
    for (int i = len_str; i >= pos; --i)
        str[i + len_s] = str[i];
    for (int i = 0; i < len_s; ++i)
        str[pos + i] = s[i];
}

void delete(int pos, int n)
{
    int len_str = strlen(str);
    n = min(n, len_str - pos);
    for (int i = pos + n; i <= len_str; ++i)
        str[i - n] = str[i];
}

void undo()
{
    if (top < 0) return ;
    if (stack[top].op == 1)
        delete(stack[top].pos, stack[top].len);
    else
        insert(stack[top].pos, stack[top].s);
    --top;
}

//1 delete, 2 insert, 3 undo, -1 end
int main()
{
    for (int i = 0; i < 512; ++i) str[i] = ' ';
    fgets(str, 512, stdin);
    int n, op, pos, len;
    char tmp_s[512];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d %s", &op, &pos, tmp_s);
        len = strlen(tmp_s);
        stack[++top].s = malloc(sizeof(char) * (len + 1));
        stack[top].op = op, stack[top].pos = pos;
        stack[top].len = len, strcpy(stack[top].s, tmp_s);
    }
    while (~scanf("%d", &op) && op != -1)
    {
        switch (op)
        {
            case 1:
                scanf("%d %s", &pos, tmp_s);
                len = strlen(tmp_s);
                stack[++top].s = malloc(sizeof(char) * (len + 1));
                insert(pos, tmp_s);
                stack[top].op = 1, stack[top].pos = pos;
                stack[top].len = len, strcpy(stack[top].s, tmp_s);
                break;
            case 2:
                scanf("%d %d", &pos, &len);
                stack[++top].s = malloc(sizeof(char) * (len + 1));
                for (int j = 0; j < len; ++j) stack[top].s[j] = str[pos + j];
                stack[top].s[len] = '\0';
                delete(pos, len);
                stack[top].op = 2, stack[top].pos = pos, stack[top].len = len;
                break;
            case 3:
                undo();
                break;
        }
    }
    printf("%s", str);
    return 0;
}