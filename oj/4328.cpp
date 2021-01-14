#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int par[N];
bool exist[N] = {0};

int find(int a)
{
    if (par[a] < 0)
        return a;
    else
        return par[a] = find(par[a]);
}

bool is_connect(int a, int b)
{
    return find(a) == find(b);
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
    int n, m;
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b;
            Union(a, b);
        }
        else if (op == 2)
        {
            cin >> a >> b;
            if (exist[a] || exist[b])
                printf("NO\n");
            else if (is_connect(a, b))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            cin >> a;
            exist[a] = 1;
        }
    }
    return 0;
}