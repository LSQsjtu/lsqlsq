#include <cstdio>
#include <cmath>

int n, m, a[100005] = {0}, dp[100005][20];

void rmq_init()
{
    for (int i = 1; i <= n; i++)
        dp[i][0] = a[i]; //初始化
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = dp[i][j - 1] > dp[i + (1 << j - 1)][j - 1] ? dp[i][j - 1] : dp[i + (1 << j - 1)][j - 1];
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
    return dp[l][k] > dp[r - (1 << k) + 1][k] ? dp[l][k] : dp[r - (1 << k) + 1][k];
}

int main()
{
    int x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    rmq_init();
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d %d", &x, &y);
        printf("%d\n", rmq(x, y));
    }
    return 0;
}