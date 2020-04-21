#include <iostream>
using namespace std;
class intervalTree
{
public:
    int l = 0, r = 0;
    int lazy = 0, info = 0; //tag 1:开房 -1:退房 info:连续房间
    int lsum = 0, rsum = 0;
    intervalTree *lc = nullptr, *rc = nullptr;

    void merge(intervalTree *x)
    {
        x->lsum = x->lc->lsum;
        x->rsum = x->rc->rsum;
        int mid = (x->l + x->r) / 2;
        if (x->lc->lsum == mid - x->l + 1)
            x->lsum += x->rc->lsum;
        if (x->rc->rsum == x->r - mid)
            x->rsum += x->lc->rsum;
        x->info = max(x->lc->rsum + x->rc->lsum, max(x->lc->info, x->rc->info));
    }

    void pushDown(intervalTree *x)
    {
        if (x->lazy != 0)
        {
            int mid = (x->l + x->r) / 2;
            x->lc->lazy = x->rc->lazy = x->lazy;
            if (x->lazy == 1)
            {
                x->lc->lsum = x->lc->rsum = x->lc->info = 0;
                x->rc->lsum = x->rc->rsum = x->rc->info = 0;
            }
            else
            {
                x->lc->lsum = x->lc->rsum = x->lc->info = mid - x->l + 1;
                x->rc->lsum = x->rc->rsum = x->rc->info = x->r - mid;
            }
            x->lazy = 0;
        }
    }

    void build(intervalTree *x, int l, int r)
    {
        x->l = l;
        x->r = r;
        if (l == r)
        {
            x->info = x->lsum = x->rsum = 1;
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
            x->lazy = c;
            if (c == 1)
                x->lsum = x->rsum = x->info = 0;
            else
                x->lsum = x->rsum = x->info = x->r - x->l + 1;
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

    int query(intervalTree *x, int len)
    {
        if (x->l == x->r)
            return x->l;
        pushDown(x);
        int mid = (x->l + x->r) / 2;
        if (x->lc->info >= len)
            return query(x->lc, len);
        if (x->lc->rsum + x->rc->lsum >= len)
            return mid - x->lc->rsum + 1;
        else
            return query(x->rc, len);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    intervalTree a;
    a.build(&a, 1, n);
    while (m--)
    {
        int op, x, y;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x;
            if (x > a.info)
                cout << 0 << '\n';
            else
            {
                y = a.query(&a, x);
                cout << y << '\n';
                a.modify(&a, y, y + x - 1, 1);
            }
            break;
        case 2:
            cin >> x >> y;
            a.modify(&a, x, x + y - 1, -1);
            break;
        }
    }
    return 0;
}