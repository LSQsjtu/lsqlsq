#include <iostream>
using namespace std;

int n, m, len = 0;
int f[100001][19], depth[100001], val[100001];
int head[100001], nxt[100001], point[100001], dis[100001]; //head连接par和son
bool isRoot[100001];

char op[8];

void dfs(int p, int par)
{
    depth[p] = depth[par] + 1; //深度
    f[p][0] = par;
    for (int i = 1; i <= 18; i++)
        f[p][i] = f[f[p][i - 1]][i - 1];
    for (int i = head[p]; i != 0; i = nxt[i])
    {
        dis[point[i]] = dis[p] + val[i];
        dfs(point[i], p);
    }
}

int LCA(int x, int y)
{
    if (depth[x] > depth[y])
        swap(x, y);
    if (x == y)
        return x;
    for (int i = 18; i >= 0; i--)
        if (depth[f[y][i]] >= depth[x])
            y = f[y][i];
    if (x == y)
        return x;
    for (int i = 18; i >= 0; i--)
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    return f[x][0];
}

int query(int a, int b, int k)
{
    int lca = LCA(a, b);
    if (depth[a] - depth[lca] + 1 >= k)
    {
        int ans = depth[a] - k + 1;
        for (int i = 18; i >= 0; i--)
            if (depth[f[a][i]] >= ans)
                a = f[a][i];
        return a;
    }
    else
    {
        int ans = depth[lca] * 2 + k - depth[a] - 1;
        for (int i = 18; i >= 0; i--)
            if (depth[f[b][i]] >= ans)
                b = f[b][i];
        return b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, n, par, son, value;
    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        cin >> par >> son >> value;
        isRoot[son] = true;
        val[i] = value;
        point[i] = son;
        nxt[i] = head[par];
        head[par] = i;
    }
    int root;
    for (int i = 1; i <= n; ++i)
    {
        if (!isRoot[i])
        {
            root = i;
            break;
        }
    }

    dfs(root, root);
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> op;
        if (op[0] == 'D')
        {
            cin >> a >> b;
            cout << dis[a] + dis[b] - dis[LCA(a, b)] * 2 << '\n';
        }
        else if (op[0] == 'K')
        {
            cin >> a >> b >> c;
            cout << query(a, b, c) << '\n';
        }
    }
    return 0;
}
// 链式前向星存的是以【1，n】为起点的边的集合

5 7 1 2 1 2 3 2 3 4 3 1 3 4 4 1 5 1 5 6 4 5 7

    1 //以1为起点的边的集合
    1 5 6 1 3 4 1 2 1

    2 //以2为起点的边的集合
    2 3 2

    3 //以3为起点的边的集合
    3 4 3

    4 //以4为起点的边的集合
    4 5 7 4 1 5

    5 //以5为起点的边不存在

/*
我们先对上面的7条边进行编号第一条边是0以此类推编号【0~6】，然后我们要知道两个变量的含义：
Next，表示与这个边起点相同的上一条边的编号。
head[i]数组，表示以 i 为起点的最后一条边的编号。

 head数组一般初始化为-1，为什么是 -1后面会讲到。加边函数是这样的

void add_edge(int u, int v, int w)//加边，u起点，v终点，w边权
{
    edge[cnt].to = v; //终点
    edge[cnt].w = w; //权值
    edge[cnt].next = head[u];//以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
    head[u] = cnt++;//更新以u为起点上一条边的编号
}
如果用链式前向星,就可以避免排序.
*/