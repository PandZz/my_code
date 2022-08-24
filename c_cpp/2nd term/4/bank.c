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
    int id, t;
};
struct queue
{
    int size, front, back;
    struct data a[1000];
} q;
void clear()
{
    q.size = q.front = 0;
    q.back = 999;
}
struct data front()
{
    return q.a[q.front];
}
void pop()
{
    q.front = (q.front + 1) % 1000;
    q.size--;
}
void push(struct data x)
{
    q.back = (q.back + 1) % 1000;
    q.a[q.back] = x;
    q.size++;
}
int T, num, current_p, current_q = 3;

void change1()
{
    if (0 <= current_p && current_p < 21) current_q = 3;
    else if (21 <= current_p && current_p < 28) current_q = 4;
    else if (28 <= current_p) current_q = 5;
}

void change2()
{
    if (current_p < 28) current_q = 3;
    else if (28 <= current_p && current_p < 35) current_q = 4;
    else current_q = 5;
}

void out(int x)
{
    if (x == 1) change1();
    else change2();
    struct data tmp;
    for (int i = 1; i <= current_q && q.size; ++i)
    {
        tmp = front();
        printf("%d : %d\n", tmp.id, T - tmp.t);
        pop();
        --current_p;
    }
}

void in(int n)
{
    struct data tmp;
    for (int i = 1; i <= n; ++i)
    {
        tmp.id = num + i, tmp.t = T;
        push(tmp);
        ++current_p;
    }
}

int main()
{
    int cnt, n;
    scanf("%d", &cnt);
    clear();
    while (cnt--)
    {
        scanf("%d", &n);
        in(n);
        out(1);
        ++T;
        num += n;
    }
    while (q.size)
    {
        out(2);
        ++T;
    }
    return 0;
}