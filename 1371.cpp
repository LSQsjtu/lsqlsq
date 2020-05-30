#include <cstdio>

int n, m, t[100000] = {0};

int main()
{
    scanf("%d %d", &n, &m);
    int x, y,Max=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        t[x]++;
    }
    while (m--)
    {
        scanf("%d %d", &x, &y);
        int result = 0;
        for (int i = x; i <= y; ++i)
        {
            result += t[i];
        }
        printf("%d\n", result);
    }

    return 0;
}