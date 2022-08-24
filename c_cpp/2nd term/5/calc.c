#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define l(i) (a[i].l)
#define r(i) (a[i].r)
#define N 205
typedef long long LL;

struct tree
{
    int isNum, isOp;
    int num, l, r;
    char op;
} a[N * 10];
char s[N], op[N];
int n, len, topOP = -1;
int t[N], topT = -1;

int level(char c)
{
    if (c == ')') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    if (c == '(') return 0;
    return -1;
}

//中缀转表达式树，中缀转后缀时，操作符栈中应保持严格递增
void postfix2tree(char s[])
{
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(s[i]))
        {
            int j = i, tmp = 0;
            while (isdigit(s[j]) && j < len)
                tmp = tmp * 10 + s[j++] - '0';
            a[++n].isNum = 1, a[n].num = tmp;
            t[++topT] = n;
            i = j - 1;
            // printf("%d\n", tmp);
        }
        if (level(s[i]) == -1) continue;

        if (topOP < 0) { op[++topOP] = s[i]; continue; }
        if (s[i] == '(' || s[i] == ')')
        {
            if (s[i] == '(') op[++topOP] = s[i];
            else
            {
                while (topOP > -1 && op[topOP] != '(')
                {
                    a[++n].isOp = 1, a[n].op = op[topOP--];
                    l(n) = t[topT - 1], r(n) = t[topT], topT -= 2;
                    t[++topT] = n;
                }
                --topOP;
            }
            continue;
        }
        if (level(s[i]) > level(op[topOP])) op[++topOP] = s[i];
        else
        {
            while (topOP > -1 && level(s[i]) <= level(op[topOP]))
            {
                a[++n].isOp = 1, a[n].op = op[topOP--];
                l(n) = t[topT - 1], r(n) = t[topT], topT -= 2;
                t[++topT] = n;
            }
            op[++topOP] = s[i];
        }
    }
}

void print(int p)
{
    if (a[p].isNum) printf("%d ", a[p].num);
    if (a[p].isOp) printf("%c ", a[p].op);
}

int calc(int p)
{
    if (a[p].isNum) return a[p].num;
    int L = calc(l(p)), R = calc(r(p));
    switch (a[p].op)
    {
        case '*':
            return L * R;
            break;
        case '/':
            return L / R;
            break;
        case '+':
            return L + R;
            break;
        case '-':
            return L - R;
            break;
        default:
            break;
    }
}

void dfs(int p)
{
    if (a[p].isNum) { print(p); return; }
    dfs(l(p)), dfs(r(p)), print(p);
}

int main()
{
    gets(s + 1);
    len = strlen(s + 1);
    s[0] = '(', s[len++] = ')';
    postfix2tree(s);
    print(n), print(l(n)), print(r(n)), putchar('\n');
    printf("%d\n", calc(n));
    return 0;
}