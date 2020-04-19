#include <iostream>
#include <cstring>
using namespace std;
int n, q;
int t[100005];
class intervalTree
{
public:
    int l = 0, r = 0;
    int lazy = 0, info = 0;
    intervalTree *lc = nullptr, *rc = nullptr;

    void merge(intervalTree *x)
    {
        x->info = x->lc->info + x->rc->info;
    }

    void pushDown(intervalTree *x)
    {
        if (x->lazy != 0)
        {
            x->lc->lazy += x->lazy;
            x->lc->info += x->lazy * (x->lc->r - x->lc->l + 1);
            x->rc->lazy += x->lazy;
            x->rc->info += x->lazy * (x->rc->r - x->rc->l + 1);
            x->lazy = 0;
        }
    }

    void build(intervalTree *x, int l, int r)
    {
        x->l = l;
        x->r = r;
        if (l == r)
        {
            x->info = t[l];
            return;
        }
        int mid = (l + r) / 2;
        x->lc = new intervalTree;
        x->rc = new intervalTree;
        build(x->lc, l, mid);
        build(x->rc, mid + 1, r);
        merge(x);
    }

    void modify(intervalTree *x, int l, int r, int c)
    {
        if (x->l >= l && x->r <= r)
        {
            x->info += c * (x->r - x->l + 1);
            x->lazy += c;
            return;
        }
        pushDown(x);
        int mid = (x->l + x->r) / 2;
        if (l <= mid)
            modify(x->lc, l, r, c);
        if (r > mid)
            modify(x->rc, l, r, c);
        merge(x);
    }

    int query(intervalTree *x, int l, int r)
    {
        if (x->l >= l && x->r <= r)
            return x->info;
        pushDown(x);
        int mid = (x->l + x->r) / 2;
        int ret = 0;
        if (l <= mid)
            ret += query(x->lc, l, r);
        if (r > mid)
            ret += query(x->rc, l, r);
        return ret;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    intervalTree a;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    a.build(&a, 1, n);
    cin >> q;
    while (q--)
    {
        char op[5];
        int x, y;
        cin >> op;
        cin >> x >> y;
        if (!strcmp(op, "QUERY"))
        {
            cout << a.query(&a, x, y) << '\n';
        }
        else if (!strcmp(op, "GET"))
        {
            a.modify(&a, x, x, y);
        }
        else
        {
            a.modify(&a, x, x, -y);
        }
    }
    return 0;
}