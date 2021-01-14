#include <stdio.h>

using namespace std;

int main()
{
    int n, k, b, c;

    scanf("%d", &n);
    int a[n] = {0};
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);
    int sum[k] = {0};
    for (int j = 0; j < k; ++j)
    {
        scanf("%d%d", &b, &c);
        for (int i = 0; i < n; ++i)
        {
            if ((b * b - 4 * a[i] * c) >= 0)
                sum[j]++;
            else
                break;
        }
    }

    for (int j = 0; j < k; ++j)
    {
        printf("%d\n", sum[j]);
    }

    return 0;
}