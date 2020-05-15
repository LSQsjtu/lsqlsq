#include <cstdio>

int n, m;
long long WPL = 0, x, a[200005];

class qenue
{
public:
    int size = 0;
    void percolateDown(int heapsize)
    {
        int i = 2;
        for (;i <= heapsize;i <<= 1)
        {
            if (i + 1 <= heapsize && a[i + 1] < a[i])
                ++i;
            if (a[i] < a[i >> 1])
            {
                {
                    long long tmp = a[i];
                    a[i] = a[i >> 1];
                    a[i >> 1] = tmp;
                }
            }
            else
                break;
        }
    }
    void percolateUp(int x)
    {
        while (x != 1)
        {
            if (a[x] < a[x >> 1])
            {
                {
                    long long tmp = a[x];
                    a[x] = a[x >> 1];
                    a[x >> 1] = tmp;
                }
                x >>= 1;
            }
            else
                break;
        }
    }
    void push(long long x)
    {
        a[++size] = x;
        percolateUp(size);
    }
    long long pop()
    {
        long long tmp = a[1];
        a[1] = a[size];
        a[size] = tmp;
        --size;
        percolateDown(size);
        return tmp;
    }
} heap;

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &x);
        heap.push(x);
    }
    long long t = n;
    while (t > m)
    {
        t = t % m + t / m;
    }
    long long k = 0;
    for (int i = 0; i < t; ++i)
    {
        k += heap.pop();
    }
    WPL += k;
    heap.push(k);
    while (heap.size != 1)
    {
        long long k = 0;
        for (int i = 0; i < m; ++i)
        {
            k += heap.pop();
        }
        WPL += k;
        heap.push(k);
    }
    printf("%lld", WPL);
    return 0;
}