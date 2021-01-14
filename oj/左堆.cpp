//左堆
#include <iostream>
using namespace std;
struct node
{
    int data = 0, dist = 0;
    node *l = nullptr, *r = nullptr;
};

node *a[300005];
bool b[300005];

node *merge(node *x, node *y)
{
    if (x == nullptr)
        return y;
    if (y == nullptr)
        return x;
    if (x->data > y->data)
        swap(x, y);
    x->r = merge(x->r, y);                          //和右子树合并
    if (x->l == nullptr || x->l->dist < x->r->dist) //交换左右子树
        swap(x->l, x->r);
    if (x->r == nullptr)
        x->dist = 0;
    else
        x->dist = x->r->dist + 1; //根节点比右节点dis大1
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        node *t = new node;
        cin >> t->data;
        a[i] = t;
        b[i] = true;
    }
    while (m--)
    {
        int opt, x, y;
        cin >> opt;
        switch (opt)
        {
        case 0:
            cin >> x >> y;
            a[x] = merge(a[x], a[y]);
            b[y] = false;
            break;
        case 1:
            cin >> x;
            if (!b[x] || a[x] == nullptr)
                cout << "-1" << '\n';
            else
            {
                cout << a[x]->data << '\n';
                a[x] = merge(a[x]->l, a[x]->r);
            }
            break;
        case 2:

            cin >> x >> y;
            node *t = new node;
            t->data = y;
            a[x] = merge(a[x], t);
            break;
        }
    }

    return 0;
}