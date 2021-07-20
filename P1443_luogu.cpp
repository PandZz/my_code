#include <bits/stdc++.h>
using namespace std;
#define R register int
const int N = 401;

struct pos
{
    int row, line;
    pos (int x, int y){row = x, line = y;}
};

pos mov[8] = {pos(1, 2), pos(1, -2), pos(-1, 2), pos(-1, -2), pos(2, 1), pos(2, -1), pos(-2 ,1), pos(-2, -1)};

int ans[N][N];
int n, m, x, y;
queue<pos> q;

inline bool is_in(pos a)
{
    if (a.row < 1) return false;
    if (a.row > n) return false;
    if (a.line < 1) return false;
    if (a.line > m) return false;
    return true;
}

void bfs()
{
    q.push(pos(x, y));
    pos org(0, 0), chg(0, 0);
    while (!q.empty())
    {
        org = q.front();
        q.pop();
        for (R i = 0; i < 8; ++i)
        {
            chg.row = org.row + mov[i].row;
            chg.line = org.line + mov[i].line;
            if (is_in(chg) && (ans[chg.row][chg.line] == -1 || ans[chg.row][chg.line] > ans[org.row][org.line] + 1))
            {
                ans[chg.row][chg.line] = ans[org.row][org.line] + 1;
                q.push(chg);
            }
        }
    }
    return ;
}

char out[6];
inline void put_out(int a)
{
    if (!a)
    {
        cout << "0    ";
        return ;
    }
    R n = 0, cnt = 0;
    if (a < 0) putchar('-'), a = -a, --cnt;
    while (a)
    {
        ++n;
        out[n] = a % 10 + '0';
        a /= 10;
    }
    for (R i = n; i >= 1; --i) putchar(out[i]);
    cnt += 5 - n;
    for (R i = 1; i<= cnt; ++i) putchar(' ');
}

int main()
{
    cin >> n >> m >> x >> y;
    for (R i = 1; i <= n; ++i)
        for (R j = 1; j <= m; ++j) ans[i][j] = -1;
    ans[x][y] = 0;
    bfs();
    for (R i = 1; i <= n; ++i)
    {
        for (R j = 1; j <= m; ++j) put_out(ans[i][j]);
        putchar('\n');
    }
    return 0;
}