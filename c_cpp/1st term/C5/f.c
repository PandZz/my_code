#include <stdio.h>
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};//平年每个月的天数
int MM[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int cal(int y, int m, int d)
{
    if ((!(y % 4) && (y % 100)) || !(y % 400))
    {
        if (m > 2) return MM[m - 1] + d + 1;
        else return MM[m - 1] + d;
    }
    return MM[m - 1] + d;
}

int solve(int a, int b)
{
    int y_a = a / 10000, y_b = b / 10000, d_a = a % 100, d_b = b % 100, m_a = (a % 10000 - d_a) / 100, m_b = (b % 10000 - d_b) / 100;
    int ans = (y_b - y_a - 1) * 365;
    ans += (y_b - 1) / 4 - y_a / 4 - ((y_b - 1) / 100 - y_a / 100) + (y_b - 1) / 400 - y_a / 400;
    ans += 365 - cal(y_a, m_a, d_a) + cal(y_b, m_b, d_b);
    if ((!(y_a % 4) && (y_a % 100)) || !(y_a % 400)) ++ans;
    return ans;
}

int check(int y)
{
    if ((!(y % 4) && (y % 100)) || !(y % 400)) return 1;
    return 0;
}

int make(int y, int m, int d) { return y * 10000 + m * 100 + d; }

int qpow(int a,int b,int p)
{
    //求(a^b) mod p 在isprime函数中会用到
    int ret=1;
    while(b)
    {
        if(b&1) ret=1ll*ret*a%p;
        a=1ll*a*a%p,b>>=1;
    }
    return ret;
}
int isprime(int n)//返回1表示n为素数，0表示n不是素数
{
    if(n==2||n==3) return 1;
    if(!(n&1)) return 0;
    int m=n-1,a,tmp,ans,cnt=0;
    while(!(m&1))
        m>>=1,cnt++;
    int rd=20011224,seed=998244353,seed2=20217371;
    for(int i=0;i<20;i++)
    {
        rd=rd*seed+seed2;
        if(rd<0) rd=-rd;
	a=rd%(n-1)+1;
        //验证费马小定理的逆定理
	tmp=qpow(a,m,n);
	for(int j=0;j<cnt;j++)
        {
	    ans=1ll*tmp*tmp%n;
	    if(ans==1)
            {
                if(tmp!=1 && tmp!=n-1)
                    return 0;
	        break ;
	    }
	    tmp=ans;
	}
	if(ans!=1) return 0;
    }
    return 1;
}

int Zeller(int y,int m,int d)
{
    if(m==1 || m==2) y--,m+=12;
    int c=y/100;y%=100;
    return ((y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7+7)%7;
}

void print(int w)
{
    switch (w)
    {
        case 0: printf("Sunday\n"); break;
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
    }
    return ;
}

int isday(int y)
{
    int d=y%100;y/=100;//日
    int m=y%100;y/=100;//月
    if(m<1 || m>12) return 0;//月必须在1-12之间
    else if(d==29&&m==2)//若是2月29日
        return (y%100&&y%4==0)||y%400==0;//合法日期的年份必须为闰年
    return d>=1 && d<=day[m];//日的区间
}

int main()
{
    int x, ls, ans, Y, M, D, lim, w, y, m, d;
    while (~scanf("%d", &x))
    {
        if (!isday(x)) { puts("-1"); continue; }
        Y = x / 10000, M = x % 10000 / 100, D = x % 100, ans = 0;

        lim = day[M];
        if (M == 2 && check(Y)) ++lim;
        for (d = D + 1; d <= lim; ++d)
        {
            ls = make(Y, M, d);
            if (isprime(ls)) { ans = ls; break; }
        }
        if (ans)
        {
            printf("%d %d ", ans, solve(x, ans));
            w = Zeller(Y, M, d);
            print(w);
            continue;
        }

        for (m = M + 1; m <= 12; ++m)
        {
            lim = day[m];
            if (m == 2 && check(Y)) ++lim;
            for (d = 1; d <= lim; ++d)
            {
                ls = make(Y, m, d);
                if (isprime(ls)) { ans = ls; break; }
            }
            if (ans) break;
        }
        if (ans)
        {
            printf("%d %d ", ans, solve(x, ans));
            w = Zeller(Y, m, d);
            print(w);
            continue;
        }

        for (y = Y + 1; y <= 9999; ++y)
        {
            for (m = 1; m <= 12; ++m)
            {
                lim = day[m];
                if (m == 2 && check(y)) ++lim;
                for (d = 1; d <= lim; ++d)
                {
                    ls = make(y, m, d);
                    if (isprime(ls)) { ans = ls; break; }
                }
                if (ans) break;
            }
            if (ans) break;
        }
        if (ans)
        {
            printf("%d %d ", ans, solve(x, ans));
            print(Zeller(y, m, d));
            continue;
        }

        puts("-1");
    }
    return 0;
}