#include <cstdio>

using namespace std;

void quickSort(long long *s, int l, int r)
{
    if (l>=r)return;
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}

int main()
{
    int n;
    long long max=0,min=0;
    scanf("%d", &n);

    long long *a, *b;
    a = new long long[n];
    b = new long long[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &b[i]);

    quickSort(a, 0, n - 1);
    quickSort(b, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        max += a[i] * b[i];
        min += a[i] * b[n - i - 1];
    }
    printf("%lld %lld", max, min);

    return 0;
}