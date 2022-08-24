#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define swap(a, b) (a ^= b, b ^= a, a ^= b)
typedef long long LL;
int n, score[1005], p[1005];
char name[1005][15];
int main()
{
    scanf("%d", &n);
    F(i, 1, n) scanf("%s%d", name[i], score + i), p[i] = i;
    F(i, 1, n - 1)
        F(j, 1, n - i)
        {
            if (score[p[j]] < score[p[j + 1]])
            {
                swap(p[j], p[j + 1]);
            }
            else if (score[p[j]] == score[p[j + 1]] && strcmp(name[p[j]], name[p[j + 1]]) > 0)
            {
                swap(p[j], p[j + 1]);
            }
        }
    // F(i, 1, n) printf("%d ", p[i]);
    F(i, 1, n) printf("%s %d\n", name[p[i]], score[p[i]]);
    return 0;
}