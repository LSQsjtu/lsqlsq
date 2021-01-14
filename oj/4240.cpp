#include <iostream>
using namespace std;
int a[4000005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, P, temp, min = 0, max = 0;
    cin >> s;
    while (s > 0)
    {
        s--;
        cin >> temp;
        if (temp < min)
            min = temp;
        if (temp > max)
            max = temp;
        a[temp + 2000000] = 1;
    }

    cin >> P;
    for (int i = 0; i < P; i++)
    {
        int b;
        cin >> b >> temp;
        if (b == 1)
        {
            if (temp < min)
                min = temp;
            if (temp > max)
                max = temp;
            a[temp + 2000000] = 1;
        }
        else
        {
            a[temp + 2000000] = 0;
        }
    }
    for (int i = min + 2000000; i <= max + 2000000; i++)
    {
        if (a[i])
        {
            cout << i - 2000000 << ' ';
        }
    }
    return 0;
}