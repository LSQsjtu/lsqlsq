#include <iostream>
using namespace std;

template <typename T>
struct priorityQueue
{
    T a[10005];
    int n;
    priorityQueue() { n = 0; }
    void push(T p)
    {
        int x = ++n;
        a[x] = p;
        for (; x > 1 && a[x] < a[x >> 1]; x >>= 1)
            swap(a[x], a[x >> 1]);
    }
    T top() { return a[1]; }
    void pop()
    {
        swap(a[1], a[n]);
        --n;
        int x = 1;
        while ((x << 1) <= n)
        {
            int y = (x << 1);
            if (y + 1 <= n && a[y + 1] < a[y])
                ++y;
            if (a[y] < a[x])
                swap(a[y], a[x]);
            else
                break;
            x = y;
        }
    }
};

int main()
{
    priorityQueue<int> q;
    int n,t;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t;
        q.push(t);
    }
    long long ans = 0;
    while (q.n > 1)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    cout << ans << endl;
    return 0;
}