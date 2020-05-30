#include <cstdio>

int m, n, parent[100005] = {0}, dp[200005][20], first[100005] = {0, 1}, sum = 1;

void rmq_init()
{
    for (int j = 1; (1 << j) <= sum; j++)
        for (int i = 1; i + (1 << j) - 1 <= sum; i++)
            dp[i][j] = dp[i][j - 1] < dp[i + (1 << j - 1)][j - 1] ? dp[i][j - 1] : dp[i + (1 << j - 1)][j - 1];
}

int log(int x)
{
    int i = 0;
    while (x >>= 1)
    {
        i++;
    }
    return i;
}

int rmq(int l, int r)
{
    int k = log(r - l + 1);
    return dp[l][k] < dp[r - (1 << k) + 1][k] ? dp[l][k] : dp[r - (1 << k) + 1][k];
}

struct son
{
    int len = 0;
    int a[100] = {0};
};

son node[100005];

void dfs(int x)
{
    son *t = &node[x];
    if (t->len > 0)
    {
        for (int i = 0; i < t->len; ++i)
        {
            first[t->a[i]] = ++sum;
            dp[sum][0] = sum;
            dfs(t->a[i]);
            ++sum;
            dp[sum][0] = first[x];
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    dp[1][0] = 1;
    int p;
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &p);
        parent[i] = p;
        node[p].a[node[p].len++] = i;
    }
    dfs(1);
    rmq_init();
    int k, l, r;
    while (m--)
    {
        scanf("%d%d%d", &k, &l, &r);
        l = first[l];
        r = first[r];

        while (k > 2)
        {
            if (l > r)
            {
                int temp = l;
                l = r;
                r = temp;
            }
            l = rmq(l, r);
            scanf("%d", &r);
            k--;
        }
        if (l > r)
        {
            int temp = l;
            l = r;
            r = temp;
        }
        printf("%d\n", rmq(l, r));
    }
    return 0;
}