#include <cstdio>
using namespace std;
void quickSort(int *s, int *t, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l], y = t[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
            {
                s[i] = s[j];
                t[i] = t[j];
                ++i;
            }
            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
            {
                s[j] = s[i];
                t[j] = t[i];
                j--;
            }
        }
        s[i] = x;
        t[i] = y;
        quickSort(s, t, l, i - 1);
        quickSort(s, t, i + 1, r);
    }
}
int main()
{
    int n, max = 1, *a, *b;
    scanf("%d", &n);
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &a[i], &b[i]);
    quickSort(b, a, 0, n - 1);
    int x = b[0];
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= x)
        {
            ++max;
            x = b[i];
        }
    }
    printf("%d", max);
    return 0;
}