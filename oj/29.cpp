#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int n, x, y;

struct myset
{
    int value = 0;
    int num = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    myset a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        int temp = x % n;
        while (1)
        {
            if (!a[temp].num)
            {
                a[temp].value = y;
                a[temp].num = 1 + a[(temp + 1) % n].num;
                break;
            }
            else
                a[temp].num++, temp = (temp + a[temp].num - 1) % n;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << a[i].value << ' ';
    return 0;
}