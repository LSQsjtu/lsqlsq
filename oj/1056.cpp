#include <iostream>
#include <cstdio>
using namespace std;
const int N = 500005;
struct node
{
    int data = 1, index = 0;
};
int n, m;
node a[N];
int par[N], pos[N];
bool b[N];

int find(int a)
{
    if (par[a] != a)
        par[a] = find(par[a]);
    return par[a];
}

void swap(int x, int y)
{
    node temp = a[x];
    a[x] = a[y];
    a[y] = temp;
    pos[a[x].index] = x;
    pos[a[y].index] = y;
}

void percolatedown(int i)
{
    int x = i, size = a[i].data;
    if (i * 2 <= n)
    {
        if (a[i * 2].data > size)
        {
            x = i * 2;
            size = a[i * 2].data;
        }
    }
    if (i * 2 + 1 <= n)
    {
        if (a[i * 2 + 1].data > size)
        {
            x = i * 2 + 1;
            size = a[i * 2 + 1].data;
        }
    }
    if (x != i)
    {
        swap(x, i);
        percolatedown(x);
    }
}

void percolateup(int i)
{
    while (i >= 2)
    {
        if (a[i].data <= a[i / 2].data)
            break;
        swap(i, i / 2);
        i /= 2;
    }
}

void remove(int i)
{
    a[i] = a[n--];
    percolatedown(i);
}

int findk(int k)
{
    int tmp = n;
    for (int i = 1; i <= k - 1; ++i)
    {
        swap(1, n);
        --n;
        percolatedown(1);
    }
    int ret = a[1].data;
    while (n < tmp)
    {
        ++n;
        percolateup(n);
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        a[i].index = i;
        par[i] = i;
        pos[i] = i;
        b[i] = true;
    }
    while (m--)
    {
        char ch;
        int x, y;
        cin >> ch;
        switch (ch)
        {
        case 'C':
        {
            cin >> x >> y;
            int xpar = find(x), ypar = find(y);
            if (!b[xpar] || !b[ypar] || xpar == ypar)
                break;
            par[xpar] = ypar;
            a[pos[ypar]].data += a[pos[xpar]].data;
            remove(pos[xpar]);
            percolateup(pos[ypar]);
            break;
        }
        case 'D':
        {
            cin >> x;
            int xpar = find(x);
            if (!b[xpar])
                break;
            remove(pos[xpar]);
            b[xpar] = false;
            break;
        }
        case 'Q':
        {
            cin >> x;
            if (n < x)
                cout << "0\n";
            else
                cout << findk(x) << '\n';
            break;
        }
        default:
            break;
        }
    }
    return 0;
}