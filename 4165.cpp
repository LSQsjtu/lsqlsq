#include <iostream>
using namespace std;
int main()
{
    int n, *a, *b, *c;
    long long sum = 0;
    cin >> n;
    a = new int[n];
    b = new int[n];
    c = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        c[i] = a[i] - b[i];
    for (int i = 0; i < n; ++i)
    {
        if (c[i] > 0)
        {
            sum += c[i];
            while ((i + 1) < n && c[i + 1] > 0)
            {
                ++i;
                if (c[i] > c[i - 1])
                    sum += c[i] - c[i - 1];
            }
        }
        else
        {
            if (c[i] < 0)
                sum -= c[i];
            while ((i + 1) < n && c[i + 1] < 0)
            {
                ++i;
                if (c[i] < c[i - 1])
                    sum -= c[i] - c[i - 1];
            }
        }
    }
    cout << sum << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}