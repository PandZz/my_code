#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct bracket
{
    char c;
    int row;
} stack[300];

char s[300], cache[300];
int top = -1, len, row, n;

int isBracket(char c)
{
    return c == '{' || c == '}' || c == '(' || c == ')';
}

int isMatch(char b)
{
    if (top < 0) return 0;
    char a = stack[top].c;
    return (a == '{' && b == '}') || (a == '(' && b == ')');
}

int main()
{
    FILE *fp = fopen("example.c", "r");
    int f1 = 0, f2 = 0;
    while (fgets(s, 300, fp) != NULL)
    {
        ++row;
        len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            if (!f2 && s[i] == '/' && s[i + 1] == '*') f1 = 1;
            if (f1)
            {
                if (s[i] == '*' && s[i + 1] == '/') f1 = 0, ++i;
                continue;
            }
            else
            {
                if (!f2 && s[i] == '/' && s[i + 1] == '/') { ++i; break; }
                if (s[i] == '"' && !f2) { f2 = 1; continue; }
                if (s[i] == '"' && f2) { f2 = 0; continue; }
            }
            if (!f1 && !f2 && isBracket(s[i]))
            {
                cache[n++] = s[i];
                switch (s[i])
                {
                    case '(':
                        stack[++top].c = s[i], stack[top].row = row;
                        break;
                    case '{':
                        if (top < 0 || stack[top].c == '{')
                            stack[++top].c = s[i], stack[top].row = row;
                        else
                        {
                            printf("without maching '%c' at line %d\n", stack[top].c, stack[top].row);
                            return 0;
                        }
                        break;
                    case ')':
                        if (isMatch(')')) --top;
                        else
                        {
                            printf("without maching '%c' at line %d\n", s[i], row);
                            return 0;
                        }
                        break;
                    case '}':
                        if (isMatch('}')) --top;
                        else
                        {
                            printf("without maching '%c' at line %d\n", s[i], row);
                            return 0;
                        }
                        break;
                }
            }
        }
    }
    if (top > -1) printf("without maching '%c' at line %d\n", stack[top].c, stack[top].row);
    else
    {
        cache[n] = '\0';
        puts(cache);
    }
    fclose(fp);
    return 0;
}