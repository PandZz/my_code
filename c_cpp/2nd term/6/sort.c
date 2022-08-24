#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

int a[105], ans, b[105];

void swap(int *p1, int *p2)
{
    int x = *p1;
    *p1 = *p2;
    *p2 = x;
}
void adjust(int *, int, int);
void merge(int *, int *, int, int, int);

void select_sort(int *, int);
void bubble_sort(int *, int);
void heap_sort(int *, int);
void merge_sort(int *, int *, int, int);
void quick_sort(int *, int, int);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    switch (m)
    {
    case 1:
        select_sort(a, n);
        break;
    case 2:
        bubble_sort(a, n);
        break;
    case 3:
        heap_sort(a, n);
        break;
    case 4:
        merge_sort(a, b, 1, n);
        break;
    case 5:
        quick_sort(a, 1, n);
        break;
    default:
        break;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n%d\n", ans);
    return 0;
}

void adjust(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j <= n - 1 && a[j] < a[j + 1])
            j++;
        ++ans;
        if (temp >= a[j])
            break;
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = temp;
}

void merge(int x[], int tmp[], int left, int leftend, int rightend)
{
    int i = left, j = leftend + 1, q = left;
    while (i <= leftend && j <= rightend)
    {
        ++ans;
        if (x[i] <= x[j])
            tmp[q++] = x[i++];
        else
            tmp[q++] = x[j++];
    }
    while (i <= leftend)
        tmp[q++] = x[i++];
    while (j <= rightend)
        tmp[q++] = x[j++];
    for (i = left; i <= rightend; i++)
        x[i] = tmp[i];
}

void select_sort(int a[], int n)
{
    int tmp;
    for (int i = 1; i < n; ++i)
    {
        tmp = i;
        for (int j = i + 1; j <= n; ++j)
            if (a[j] < a[tmp])
                tmp = j;
        swap(a + i, a + tmp);
    }
    ans = n * (n - 1) / 2;
}

void bubble_sort(int a[], int n)
{
    int i, j, flag = 1;
    int tmp;
    i = n - 1;
    while (i > 0 && flag == 1)
    {
        flag = 0;
        for (j = 1; j <= i; ++j)
            if (a[j] > a[j + 1])
            {
                swap(a + j, a + j + 1);
                flag = 1;
            }
        ans += i;
        --i;
    }
}

void heap_sort(int a[], int n)
{
    int i;
    int tmp;
    for (i = n / 2; i >= 1; --i)
        adjust(a, i, n);
    for (i = n - 1; i >= 1; --i)
    {
        b[i + 1] = a[1];
        swap(a + 1, a + i + 1);
        adjust(a, 1, i);
    }
    b[1] = a[1];
    for (i = 1; i <= n; ++i) a[i] = b[i];
}

void merge_sort(int k[], int tmp[], int left, int right)
{
    int center;
    if (left < right)
    {
        center = (left + right) / 2;
        merge_sort(k, tmp, left, center);
        merge_sort(k, tmp, center + 1, right);
        merge(k, tmp, left, center, right);
    }
}

void quick_sort(int k[], int left, int right)
{
    int i, last;
    if (left < right)
    {
        last = left;
        for (i = left + 1; i <= right; i++)
        {
            if (k[i] < k[left])
                swap(&k[++last], &k[i]);
            ++ans;
        }
        swap(&k[left], &k[last]);
        quick_sort(k, left, last - 1);
        quick_sort(k, last + 1, right);
    }
}
