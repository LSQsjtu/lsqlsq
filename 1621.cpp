#include <iostream>
using namespace std;
void quickSort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] < x) // 从右向左找第一个大于等于x的数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] >= x) // 从左向右找第一个小于x的数
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
    int n, **a, max = 0;
    char c;
    cin >> n;
    a = new int *[n];
    for (int i = 0; i < n; ++i)
        a[i] = new int[n];
    for (int i = -1; i < n; ++i)
    {
        int j = 0, sum = 0;
        while ((c = cin.get()) != '\n')
        {
            a[i][j] = c - '0';
            if (a[i][j] == 1)
            {
                sum++;
                a[i][j] = sum;
            }
            else
            {
                sum = 0;
            }
            ++j;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int *s;
        s = new int[n];
        for (int i = 0; i < n; ++i)
        {
            s[i] = a[i][j];
        }
        quickSort(s, 0, n - 1);
        for (int i = 0; i < n; ++i)
        {
            if ((i + 1) * s[i] >= max)
                max = (i + 1) * s[i];
        }
        delete[] s;
    }
    cout << max << endl;
    return 0;
}