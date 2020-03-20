#include <iostream>
using namespace std;
int main()
{
    int n, *a;
    cin >> n;
    a = new int[n + 1];
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        a[i] = 0;
        for (int b = 0; b <= i; ++b)
        {
            if ((i - b) % 2 == 0)
            {
                a[i] += a[(i - b) / 2];
            }
        }
        a[i] %= 1000000007;
    }
    cout << a[n] << endl;
    return 0;
}