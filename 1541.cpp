//单调递减双端队列
#include <cstdio>

int k, n;
int a[200005], dp[200005], head = 0, ptr = -1;

int main()
{
    scanf("%d", &k);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k - 1; ++i)
    {
        while (ptr >= 0 && a[i] >= a[dp[ptr]])//小的话就都移除
            ptr--;
        dp[++ptr] = i;
    }

    for (int i = k - 1; i < n; ++i)
    {
        while (dp[head] <= i - k)
            head++;
        while (a[i] >= a[dp[ptr]] && ptr >= head)
            ptr--;
        dp[++ptr] = i;
        printf("%d ", a[dp[head]]);
    }

    return 0;
}
