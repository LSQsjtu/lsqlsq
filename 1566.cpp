#include <iostream>
#include <cstring>

using namespace std;

int par[30];
int n, m;

struct edge
{
    int u = 0, v = 0, dis = 0;
    bool operator<(edge &p)
    {
        return dis < p.dis;
    }
    bool operator>=(edge &p)
    {
        return dis >= p.dis;
    }
} Edge[76];

void quickSort(edge s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        edge x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}

int find(int a)
{
    if (par[a] < 0)
        return a;
    else
        return par[a] = find(par[a]);
}

void Union(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b)
    {
        if (par[a] < par[b])
        {
            par[a] += par[b];
            par[b] = a;
        }
        else
        {
            par[b] += par[a];
            par[a] = b;
        }
    }
}

int main()
{
    char s;
    int k, dis, u, v;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> s >> k;
        u = s - 'A' + 1;
        for (int j = 0; j < k; j++)
        {
            cin >> s >> dis;
            Edge[m].u = u;
            Edge[m].v = s - 'A' + 1;
            Edge[m].dis = dis;
            m++;
        }
    }
    quickSort(Edge, 0, m - 1);
    memset(par, -1, sizeof(par));
    int num = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        u = Edge[i].u;
        v = Edge[i].v;
        if (find(u) != find(v))
        {
            sum += Edge[i].dis;
            num++;
            Union(u, v);
        }
        if (num >= n - 1)
            break;
    }
    printf("%d\n", sum);
    return 0;
}