#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct student
{
    int id, seat;
    char name[25];
} T[105];
int n, m, cSeat[105];

int cmp_seat(struct student *p1, struct student *p2)
{
    return p1->seat != p2->seat ? p1->seat - p2->seat : p1->id - p2->id;
}

int cmp_id(struct student *p1, struct student *p2)
{
    return p1->id - p2->id;
}

int main()
{
    FILE *Src = fopen("in.txt", "r"), *Obj = fopen("out.txt", "w");
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        fscanf(Src, "%d %s %d", &T[i].id, T[i].name, &T[i].seat);
        cSeat[T[i].seat]++;
    }
    qsort(T + 1, n, sizeof(struct student), cmp_seat);
    int l = 1, r = n;
    while (l < T[r].seat)
    {
        if (!cSeat[l])
        {
            cSeat[T[r].seat]--, cSeat[l]++;
            T[r].seat = l;
            --r;
        }
        ++l;
    }
    m = 0;
    for (int i = 1; i <= n; ++i) m = max(m, T[i].seat);
    // printf("m = %d\n", m);
    for (int i = 1; i <= n; ++i)
    {
        while (cSeat[T[i].seat] > 1)
        {
            T[i + cSeat[T[i].seat] - 1].seat = ++m;
            cSeat[T[i].seat]--;
        }
    }
    qsort(T + 1, n, sizeof(struct student), cmp_id);
    for (int i = 1; i <= n; ++i)
        fprintf(Obj, "%d %s %d\n", T[i].id, T[i].name, T[i].seat);
    return 0;
}