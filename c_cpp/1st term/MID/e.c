#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
const double eps = 1e-6;
typedef long long LL;
int num[305], n;
double score[305];

double myAbs(double x) { return x > 0 ? x : -x; }

int main()
{
    scanf("%d", &n);
    F(i, 1, n) scanf("%8d %lf", num + i, score + i);
    double lsD;
    int lsI;
    F(i, 1, n - 1)
        F(j, 1, n - i)
        {
            if (myAbs(score[j] - score[j + 1]) < eps)
            {
                if (num[j] > num[j + 1])
                {
                    lsI = num[j], num[j] = num[j + 1], num[j + 1] = lsI;
                    lsD = score[j], score[j] = score[j + 1], score[j + 1] = lsD;
                }
            }
            else if (score[j] > score[j + 1])
            {
                lsI = num[j], num[j] = num[j + 1], num[j + 1] = lsI;
                lsD = score[j], score[j] = score[j + 1], score[j + 1] = lsD;
            }
        }
    F(i, 1, n) printf("%08d %.2lf\n", num[i], score[i]);
    return 0;
}