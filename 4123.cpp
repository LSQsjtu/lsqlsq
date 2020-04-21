#include <iostream>
using namespace std;

char t[100005];
void quickSort(char s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        char x = s[l];
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
void fanquickSort(char s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        char x = s[l];
        while (i < j)
        {
            while (i < j && s[j] <= x) // 从右向左找第一个大于x的数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] > x) // 从左向右找第一个小于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        fanquickSort(s, l, i - 1);
        fanquickSort(s, i + 1, r);
    }
}
/*class intervalTree
{
public:
    int l = 0, r = 0;
    int lazy = 0;
    intervalTree *lc = nullptr, *rc = nullptr;

    void pushDown(intervalTree *x)
    {
        if (x->lazy != 0)
        {
            switch (x->lazy)
            {
            case 1:
                fanquickSort(t, x->l, x->r);
                break;
            case -1:
                quickSort(t, x->l, x->r);
                break;
            default:
                break;
            }
            x->lc->lazy = x->lazy;
            x->rc->lazy = x->lazy;
            x->lazy = 0;
        }
    }

    void build(intervalTree *x, int l, int r)
    {
        x->l = l;
        x->r = r;
        if (l == r)
        {
            return;
        }
        int mid = (l + r) / 2;
        x->lc = new intervalTree;
        x->rc = new intervalTree;
        build(x->lc, l, mid);
        build(x->rc, mid + 1, r);
    }

    void modify(intervalTree *x, int l, int r, int c)
    {
        if (x->l >= l && x->r <= r)
        {
            x->lazy = c;
            return;
        }
        pushDown(x);
        int mid = (x->l + x->r) / 2;
        if (l <= mid)
            modify(x->lc, l, r, c);
        if (r > mid)
            modify(x->rc, l, r, c);
    }
    void query(intervalTree *x)
    {
        if(x->lazy==0)
        {
            query(x->lc);
            query(x->rc);
        }
    }
};*/

int main()
{
    int n, q;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    //intervalTree a;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
   // a.build(&a, 1, n);
    while (q--)
    {
        int x, l, r;
        cin >> l >> r >> x;
        switch (x)
        {
        case 0:
            //a.modify(&a, l, r, 1);
            fanquickSort(t, l, r);
            break;
        case 1:
           // a.modify(&a, l, r, -1);
           quickSort(t, l, r);
            break;
        default:
            break;
        }
    }
    //a.query(&a);
    for (int i = 1; i <= n; ++i)
        cout << t[i];
    return 0;
}