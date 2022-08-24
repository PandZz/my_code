#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

char str[205];
double num[200];

void print(char *str)
{
    int first = 0;
    while (*str != '\0')
    {
        if (isalpha(*str))
        {
            if (!first) printf("%.2lf", num[*str]), first = 1;
            else printf(" %.2lf", num[*str]);
        }
        ++str;
    }
    printf("\n");
}

int level(char c)
{
    if (c == ')') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    if (c == '(') return 0;
    return -1;
}

double cal(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
    return 0;
}

int top_op = -1, top_n = -1;
char op[200];
double n[200];
double calc(char *str)
{
    int len = strlen(str);
    str[0] = '(', str[len] = ')', str[++len] = '\0';
    while (*str != '\0')
    {
        if (isdigit(*str))
        {
            int tmp = 0;
            while (isdigit(*str))
                tmp = tmp * 10 + *str - '0', ++str;
            n[++top_n] = (double)tmp;
            continue;
        }
        if (isalpha(*str)) { n[++top_n] = num[*str], ++str; continue; }
        if (top_op < 0) { op[++top_op] = *str, ++str; continue; }
        if (*str == '(' || *str == ')')
        {
            if (*str == '(') op[++top_op] = *str;
            else
            {
                double tmp = 0;
                while (top_op > -1 && op[top_op] != '(')
                {
                    tmp = cal(n[top_n - 1], n[top_n], op[top_op]);
                    n[--top_n] = tmp, --top_op;
                }
                --top_op;
            }
            ++str;
            continue;
        }
        if (level(*str) > level(op[top_op])) op[++top_op] = *(str++);
        else
        {
            double tmp = 0;
            while (top_op > -1 && level(*str) <= level(op[top_op]))
            {
                tmp = cal(n[top_n - 1], n[top_n], op[top_op]);
                n[--top_n] = tmp, --top_op;
            }
            op[++top_op] = *(str++);
        }
    }
    return n[top_n];
}

int main()
{
    while (gets(str) != NULL)
    {
        if (strstr(str, "exit") != NULL) break;
        if (strstr(str, "print"))
            print(str + 5);
        else
            num[str[0]] = calc(str + 1);
    }
    return 0;
}