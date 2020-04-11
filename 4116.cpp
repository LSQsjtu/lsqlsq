#include <iostream>
using namespace std;
void quickSort(int s[], int l, int r)
{
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
    int n, s, *a, length;
    cin >> n >> s;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    int l = 1, r = a[n - 1];
    while (l < r)
    {
        int m = (r + l + 1) / 2;
        int j = 0, t = s;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[j] >= m)
            {
                t--;
                j = i;
            }
        }
        if (t <= 1)
        {
            l = m;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << l << endl;
    return 0;
}