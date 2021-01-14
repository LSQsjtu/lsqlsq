#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10001;
struct Vector
{
    int *x;
    int cap;
    int size = 0;
    Vector(int cap = 16) : cap(cap)
    {
        x = new int[cap];
    }

    void push_back(int y)
    {
        if (cap == size)
        {
            int *buffer = new int[cap * 2];
            memcpy(buffer, x, sizeof(int) * cap);
            cap *= 2;
            delete[] x;
            x = buffer;
        }
        x[size++] = y;
    }
};
Vector G[maxn];
int n;
bool ans[maxn] = {0};
int dfs(int node, int father)
{
    int sum = 1, childmax = 0;
    for (int i = 0; i < G[node].size; i++)
    {
        if (G[node].x[i] == father)
            continue; //因为是树结构，这里可以在无向时避免遍历成环
        int sum_son = dfs(G[node].x[i], node);
        childmax = max(sum_son, childmax); //所有子树的结点数的最大值
        sum += sum_son;
    }
    childmax = max(childmax, n - sum);
    if (childmax <= n / 2)
    {
        ans[node] = 1;
    }
    return sum;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);

    for (int i = 1; i <= maxn; ++i)
        if (ans[i])
            printf("%d\n", i);
    return 0;
}