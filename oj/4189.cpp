#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d = 0, node *n = NULL) : data(d), next(n) {}
};

node son[100000] = {0};
int father[100000] = {0}, Size[100000] = {0};
bool isInNode[100000]={0};

int dfs(int x)
{
    if (son[x].next == NULL)
    {
        return 1;
    }
    else
    {
        node *p = son + x;
        while (p->next != NULL)
        {
            p = p->next;
            Size[x] += dfs(p->data);
        }
        return Size[x] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k = 0, root;
    cin >> n;
    for (int i = 1; i < n; i++) //假设u<v
    {
        int u, v;
        cin >> u >> v;
        son[u].data = u;
        son[v].data = v;
        if (!isInNode[v])
        {
            node *p = son + u;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new node(v);
            father[v] = u;
        }
        else if (isInNode[v] && isInNode[u])
        {
            node *p = son + v;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = new node(u);
            father[u] = v;
            isInNode[u] = isInNode[v] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (father[i] == 0)
        {
            root = i;
            break;
        }
    }

    dfs(root);

    for (int i = 1; i <= n; i++)
    {
        bool flag = 1;
        node *p = son + i;
        while (p->next != NULL)
        {
            p = p->next;
            if (Size[p->data] > n / 2)
            {
                flag = 0;
                break;
            }
        }
        if (n - Size[i] - 1 > n / 2)
        {
            flag = 0;
        }
        if (flag)
        {
            cout << i << '\n';
        }
    }

    return 0;
}
