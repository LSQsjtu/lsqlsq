#include <iostream>
using std::cin;
using std::cout;

int k, l;

struct set
{
    int x = 0;
    int y = 0; //第几组
    int z = 0; //第几个
    bool operator<(set t)
    {
        return x < t.x;
    }
};
set b[10000][200];

template <typename T>
struct priorityQueue
{
    T a[10005];
    int n;
    priorityQueue() { n = 0; }
    void swap(int x, int y)
    {
        set temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
    void push(T p)
    {
        int x = ++n;
        a[x] = p;
        for (; x > 1 && a[x] < a[x >> 1]; x >>= 1)
            swap(x, x >> 1);
    }
    T top() { return a[1]; }
    void pop()
    {
        cout << a[1].x << ' ';
        swap(1, n);
        --n;
        int x = 1;
        while ((x << 1) <= n)
        {
            int y = (x << 1);
            if (y + 1 <= n && a[y + 1] < a[y])
                ++y;
            if (a[y] < a[x])
                swap(y, x);
            else
                break;
            x = y;
        }
    }
};

int main()
{
    cin >> k >> l;
    priorityQueue<set> tree;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> b[i][j].x;
            b[i][j].y = i, b[i][j].z = j;
        }
    }
    for (int i = 0; i < k; i++)
        tree.push(b[i][0]);
    for (int i = 0; i < k * l; i++)
    {
        set temp = tree.top();
        tree.pop();
        if (temp.z + 1 < l)
            tree.push(b[temp.y][temp.z + 1]);
    }
    return 0;
}