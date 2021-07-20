#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define R register int
using namespace std;

inline string my_copy(int t, string s)
{
    string ans = "";
    while (t)
    {
        if (t & 1) ans += s;
        s += s, t >>= 1;
    }
    return ans;
}

string solve(string org)
{
    string ans, ls;
    int n = org.length();
    R i = 0;
    while (i < n)
    {
        if (org[i] != '[') ans += org[i], ++i;
        else
        {
            ls = "";
            ++i;
            R  t = 0, cnt = 1;
            // get number
            while (org[i] >= '0' && org[i] <= '9')
            {
                t = t * 10 + org[i] - '0';
                ++i;
            }
            while (cnt)
            {
                if (org[i] == '[') ++cnt;
                else if (org[i] == ']') --cnt;
                ls += org[i];
                ++i;
            }
            ls.erase(ls.end() - 1);
            ans += my_copy(t, solve(ls));
        }
    }
    return ans;
}

int main()
{
    string a;
    cin >> a;
    cout << solve(a);
    return 0;
}