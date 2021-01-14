/*
线段树/bit优化dp。

设f[i][j][0/1]表示考虑了前i个点，有j段折线，且最后一段是上升/下降的方案数。

可以得到一个很显然的转移：

f[i][k][0]=∑j=1到i−1f[j][k][0]∗[a[i]>a[j]]+f[j][k−1][1]∗[a[i]>a[j]]
f[i][k][1]=∑j=1到i−1f[j][k−1][0]∗[a[i]<a[j]]+f[j][k][1]∗[a[i]<a[j]]
注意到k的范围只有10，可以暴力枚举后两维，然后用一颗权值线段树来维护第一维。
*/
#include <bits/stdc++.h>
using namespace std;
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -f;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    x *= f;
}

#define maxn 100005
const int mod = 100007;
int f[maxn][11][2], n, K;
struct point
{
    int x, y;
} a[maxn];
inline int cmp(point x, point y) { return x.x < y.x; }
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)
struct segment_tree
{
    int sum[maxn << 2];
    void update(int p) { sum[p] = sum[ls] + sum[rs]; }
    void modify(int p, int l, int r, int x, int v)
    {
        if (l == r)
            return sum[p] = v % mod, void();
        if (x <= mid)
            modify(ls, l, mid, x, v);
        else
            modify(rs, mid + 1, r, x, v);
        update(p);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (!y)
            return 0;
        if (x <= l && r <= y)
            return sum[p];
        int ans = 0;
        if (x <= mid)
            ans = (ans + query(ls, l, mid, x, y)) % mod;
        if (y > mid)
            ans = (ans + query(rs, mid + 1, r, x, y)) % mod;
        update(p);
        return ans;
    }
} T[11][2];
#define N 100000
int main()
{
    read(n), read(K);
    for (int i = 1; i <= n; i++)
        read(a[i].x), read(a[i].y);
    sort(a + 1, a + n + 1, cmp);
    //for(int i=1;i<=n;i++) printf("%d %d\n",a[i].x,a[i].y);
    for (int i = 1; i <= n; i++)
    {
        f[i][0][0] = f[i][0][1] = 1;
        T[0][0].modify(1, 1, N, a[i].y, 1), T[0][1].modify(1, 1, N, a[i].y, 1);
        for (int k = 1; k <= K; k++)
        {
            f[i][k][0] = (T[k][0].query(1, 1, N, 1, a[i].y - 1) + T[k - 1][1].query(1, 1, N, 1, a[i].y - 1)) % mod;
            f[i][k][1] = (T[k][1].query(1, 1, N, a[i].y + 1, N) + T[k - 1][0].query(1, 1, N, a[i].y + 1, N)) % mod;
            T[k][0].modify(1, 1, N, a[i].y, f[i][k][0]), T[k][1].modify(1, 1, N, a[i].y, f[i][k][1]);
            //if(i==3) printf("::%d\n",T[k][1].query(1,1,N,5,5));
            //printf("%d %d\n",f[i][1][0],f[i][1][1]);
        }
    }
    int ans = 0;
    //for(int i=1;i<=n;i++) printf("%d %d\n",f[i][1][0],f[i][1][1]);
    for (int i = 1; i <= n; i++)
        ans = (ans + f[i][K][0] + f[i][K][1]) % mod;
    printf("%d\n", ans);
    return 0;
}