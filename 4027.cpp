#include <iostream>
using namespace std;

int a[100005] = {0}, b[100005] = {0}, c[100005] = {0};//b为a中对应位置，c记录选了那个

int search(int ans[], int l, int r, int x)
{
    if (l >= r)
        return l;
    int m = (l + r) / 2;
    if (ans[m] < x)
        return search(ans, m + 1, r, x);
    else
        return search(ans, l, m, x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x=0,j = 0, len = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        b[i] = a[x];
        if (b[i] > c[len])
            j = ++len;
        else
            j = search(c, 1, len, b[i]);
        c[j] = b[i];
    }

    cout << len << endl;
    return 0;
}