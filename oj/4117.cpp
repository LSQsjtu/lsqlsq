#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100001;
typedef long long ll;
ll a[MAXN], ans[4 * MAXN], tag[4 * MAXN];
inline int ls(int p)
{
    return p << 1;
}

inline int rs(int p)
{
    return p << 1 | 1;
}

inline void push_up(int p)
{
    ans[p] = ans[ls(p)] + ans[rs(p)];
}

void build(int l, int r, int p)
{
    if (l == r)
    {
        ans[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls(p));
    build(mid + 1, r, rs(p));
    push_up(p);
}

inline void add_tag(int p, int l, int r, int k)
{
    tag[p] += k;
    ans[p] += k * (r - l + 1);
}

inline void push_down(int p, int l, int r)
{
    int mid = (l + r) >> 1;
    add_tag(ls(p), l, mid, tag[p]);
    add_tag(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}

void update(int nl, int nr, int l, int r, int p, int k)
{
    if (nl <= l && r <= nr)
    {
        add_tag(p, l, r, k);
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (nl <= mid)
        update(nl, nr, l, mid, ls(p), k);
    if (nr > mid)
        update(nl, nr, mid + 1, r, rs(p), k);
    push_up(p);
}

ll query(int nl, int nr, int l, int r, int p)
{
    if (nl <= l && r <= nr)
        return ans[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll sum = 0;
    if (nl <= mid)
        sum += query(nl, nr, l, mid, ls(p));
    if (nr > mid)
        sum += query(nl, nr, mid + 1, r, rs(p));
    return sum;
}
int m, n, x, y, k;
char c;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, n, 1);
    for (int i = 0; i < m; ++i)
    {
        c = ' ';
        while (c != 'C' && c != 'Q')
            c = getchar();
        if (c == 'C')
        {
            scanf("%d%d%d", &x, &y, &k);
            update(x, y, 1, n, 1, k);
        }
        if (c == 'Q')
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}
//自己实现
#include <iostream>
using namespace std;
int n, q;
long long t[100005];
class intervalTree
{
public:
    int l = 0, r = 0;
    long long lazy = 0, info = 0;
    intervalTree *lc=nullptr, *rc=nullptr;

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
        x->lc=new intervalTree;
        x->rc=new intervalTree;
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

    long long query(intervalTree *x, int l, int r)
    {
        if (x->l >= l && x->r <= r)
            return x->info;
        pushDown(x);
        int mid = (x->l + x->r) / 2;
        long long ret = 0;
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
    cin >> n >> q;
    intervalTree a;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    a.build(&a, 1, n);
    while (q--)
    {
        char op;
        int x, y, z;
        cin >> op;
        if (op == 'Q')
        {
            cin >> x >> y;
            cout << a.query(&a, x, y) << '\n';
        }
        else
        {
            cin >> x >> y >> z;
            a.modify(&a, x, y, z);
        }
    }
    return 0;
}