#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define opIndex(a) ((a == '*' || a == '/') ? 2 : 1)
#define isOp(a) ((a == '*' || a == '/' || a == '+' || a == '-') ? 1 : 0)
#define isBracket(a) ((a == '(' || a == ')') ? 1 : 0)
typedef long long LL;

struct exp
{
    int is_num;
    union val
    {
        char op;
        int num;
    } data;
};

//接受后缀表达式字符串, 返回中缀表达式的struct exp数组的头指针, end with: is_num = -1
struct exp *infix2postfix(char *);
//返回不是数字的下一位
char *getNumStr(char *);
//从指针1到<指针2计算返回代表的数值
int getNumVal(char *, char *);
//从中缀表达式计算结果
double calPostfix(struct exp *);
//根据运算符计算值
double calVal(double, char, double);

int main()
{
    char str[200];
    fgets(str + 1, 200, stdin);
    int len = strlen(str + 1);
    str[0] = '(', str[len + 1] = ')', str[len + 2] = '\0';
    printf("%.2lf\n", calPostfix(infix2postfix(str)));
    return 0;
}

struct exp *infix2postfix(char s[])
{
    int len = strlen(s), top_op = -1;
    char stack_op[200], *tmpP;
    struct exp *postfix = malloc(sizeof(struct exp) * 200), *p;
    p = postfix;
    for (char *i = s; i - s < len; ++i)
    {
        if (isdigit(*i))
        {
            tmpP = getNumStr(i);
            p->is_num = 1;
            p->data.num = getNumVal(i, tmpP);
            i = tmpP - 1;
            ++p;
        }
        else if (isBracket(*i))
        {
            if (*i == '(') stack_op[++top_op] = *i;
            else
            {
                while (top_op > -1 && stack_op[top_op] != '(')
                {
                    p->is_num = 0;
                    p->data.op = stack_op[top_op--];
                    ++p;
                }
                top_op--;
            }
        }
        else if (isOp(*i))
        {
            while (top_op > -1 && stack_op[top_op] != '(' && opIndex(*i) <= opIndex(stack_op[top_op]))
            {
                p->is_num = 0;
                p->data.op = stack_op[top_op--];
                ++p;
            }
            stack_op[++top_op] = *i;
        }
    }
    p->is_num = -1;
    return postfix;
}

char *getNumStr(char *p)
{
    while (isdigit(*p)) ++p;
    return p;
}

int getNumVal(char *p1, char *p2)
{
    int s = 0;
    while (p1 != p2)
    {
        s = s * 10 + *p1 - '0';
        p1++;
    }
    return s;
}

double calVal(double a, char op, double b)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

double calPostfix(struct exp *s)
{
    double tmp = 0, stack_num[200];
    int top_num = -1;
    while (s->is_num != -1)
    {
        if (s->is_num)
            stack_num[++top_num] = (double)s->data.num;
        else
        {
            tmp = calVal(stack_num[top_num - 1], s->data.op, stack_num[top_num]);
            stack_num[--top_num] = tmp;
        }
        s++;
    }
    return stack_num[top_num];
}