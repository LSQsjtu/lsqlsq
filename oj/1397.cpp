#include <iostream>

using namespace std;
#include <iostream>

using namespace std;

void quickSort(long long s[], int l, int r)
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
    int n;
    long long *p, max = 0;
    cin >> n;
    p = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    quickSort(p, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        max += p[i] * (2 * i - n + 1);
        max %= 1000000007;
    }
    cout << max << endl;
    return 0;
}