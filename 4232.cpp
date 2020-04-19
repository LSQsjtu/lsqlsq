#include <iostream>
using namespace std;

int t[200005], n, q;

class intervalTree
{
public:
    int l = 0, r = 0;
    int info = 0;
    intervalTree *lc = nullptr, *rc = nullptr;

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
        x->info = max(x->lc->info, x->rc->info);
    }

    void modify(intervalTree *x, int pos, int c)
    {
        if (x->l == x->r)
        {
            x->info = c;
            return;
        }
        int mid = (x->l + x->r) / 2;
        if (pos <= mid)
            modify(x->lc, pos, c);
        else
            modify(x->rc, pos, c);
        x->info = max(x->lc->info, x->rc->info);
    }

    int query(intervalTree *x, int l, int r)
    {
        if (x->l >= l && x->r <= r)
            return x->info;
        int mid = (x->l + x->r) / 2;
        int ret = 0, let = 0;
        if (l <= mid)
            let = query(x->lc, l, r);
        if (r > mid)
            ret = query(x->rc, l, r);
        return ret > let ? ret : let;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    intervalTree a;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    a.build(&a, 1, n);
    while (q--)
    {
        char op;
        int x, y;
        cin >> op;
        cin >> x >> y;
        if (op == 'Q')
        {
            cout << a.query(&a, x, y) << '\n';
        }
        else
        {
            a.modify(&a, x, y);
        }
    }
    return 0;
}