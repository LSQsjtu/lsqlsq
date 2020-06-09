#include <iostream>
using namespace std;

int a[100005], tree[100005],dis[100005] = {0};
bool b[100005];
int parent[100005], Next[200005], pre[200005], e[200005];
int treesize = 0, n = 0, cnt = 0;

void add(int u, int v)
{
    Next[++cnt] = parent[u];
    if (parent[u] != 0)
        pre[parent[u]] = cnt;
    parent[u] = cnt;
    e[cnt] = v;
    ++dis[u];
    ++dis[v];
}

void erase(int u, int x)
{
    if (Next[x] != 0)
        pre[Next[x]] = pre[x];
    if (pre[x] != 0)
        Next[pre[x]] = Next[x];
    else
        parent[u] = Next[x];
    pre[x] = Next[x] = 0;
}

void swap(int x, int y)
{
    int t = tree[x];
    tree[x] = tree[y];
    tree[y] = t;
}

void remove()
{
    swap(1, treesize);
    --treesize;
    int i = 2;
    while (i <= treesize)
    {
        if (i + 1 <= treesize && tree[i + 1] < tree[i])
            ++i;
        if (tree[i / 2] > tree[i])
        {
            swap(i / 2, i);
            i *= 2;
        }
        else
            break;
    }
}

void insert(int x)
{
    tree[++treesize] = x;
    int i = treesize;
    while (i != 1)
    {
        if (tree[i] < tree[i / 2])
        {
            swap(i, i / 2);
            i /= 2;
        }
        else
            break;
    }
}

void buildTree(int root)
{
    char ch;
    int num = 0;
    cin >> num;
    cin >> ch;

    if (num > n)
        n = num;
    if (root)
    {
        add(num, root);
        add(root, num);
    }
    a[num] = num;
    while (ch == '(')
    {
        buildTree(num);
        cin >> ch;
    }
}

int main()
{
    char ch;
    cin >> ch;
    buildTree(0);
    for (int i = 1; i <= n; ++i)
    {
        if (dis[a[i]] == 2)
            insert(a[i]);
        b[i] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        int t = tree[1];
        cout << e[parent[t]] << ' ';
        b[t] = false;
        remove();
        int j = parent[t];
        int u = e[j];
        erase(t, j);
        if (j % 2)
            erase(u, j + 1);
        else
            erase(u, j - 1);
        dis[u] -= 2;
        if (dis[u] == 2)
            insert(u);
    }
    return 0;
}