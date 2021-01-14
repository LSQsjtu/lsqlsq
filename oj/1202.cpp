#include <iostream>
using namespace std;
void f(long long a)
{
    int arr[12] = {0}, i = 0, j = 0;
    while (a != 0)
    {
        arr[i] = a % 10;
        a /= 10;
        ++i;
    }
    if (i == 1)
        cout << (((1 + arr[0]) * arr[0]) / 2) % 10 << endl;
    else
    {
        if (arr[0] == 9)
        {
            if (arr[1] % 2 == 1)
                cout << 0 << endl;
            else
                cout << 5 << endl;
        }
        else
        {
            for (j = 0; j < i - 1; ++j)
                if ((arr[i - j - 1] * (arr[0] + 1)) % 10 != 0)
                {
                    cout << (arr[i - j - 1] * (arr[0] + 1)) % 10;
                    break;
                }
            for (j = j + 1; j < i - 1; ++j)
                cout << (arr[i - j - 1] * (arr[0] + 1)) % 10;
            if (arr[1] % 2 == 1)
                cout << (5 + ((1 + arr[0]) * arr[0]) / 2) % 10 << endl;
            else
                cout << (((1 + arr[0]) * arr[0]) / 2) % 10 << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    long long *a;
    a = new long long[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < n; ++j)
        f(a[j]);
    return 0;
}