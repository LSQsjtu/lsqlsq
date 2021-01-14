//24点
#include <iostream>
#include <cmath>
using namespace std;
int sum = 0;
void f(int *a, int len)
{
    if (len == 1)
    {
        if (sum < a[0] && a[0] <= 24)
            sum = a[0];
        return;
    }
    int *pnew;
    pnew = new int[len - 1];

    for (int i = 1; i < len; ++i)
        for (int j = 0; j < i; ++j)
            for (int k = 1; k <= 4; ++k)
            {
                for (int m = 1, n = 0; m < len - 1; ++m)
                {
                    while (n == i || n == j)
                        n++;
                    pnew[m] = a[n++];
                }
                switch (k)
                {
                case 1:
                    pnew[0] = a[i] + a[j];
                    f(pnew, len - 1);
                    break;
                case 2:
                    pnew[0] = abs(a[i] - a[j]);
                    f(pnew, len - 1);
                    break;
                case 3:
                    pnew[0] = a[i] * a[j];
                    f(pnew, len - 1);
                    break;
                case 4:
                    if (a[j] != 0 && (a[i] % a[j]) == 0)
                    {
                        pnew[0] = a[i] / a[j];
                        f(pnew, len - 1);
                    }
                    else if (a[i] != 0 && (a[j] % a[i]) == 0)
                    {
                        pnew[0] = a[j] / a[i];
                        f(pnew, len - 1);
                    }
                    else
                        return;
                    break;
                default:
                    break;
                }
            }
}
int main()
{
    int n;
    cin >> n;
    int *max;
    max = new int[n];
    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        f(a, 4);
        max[i] = sum;
    }
    for (int i = 0; i < n; ++i)
        cout << max[i] << endl;
    return 0;
}