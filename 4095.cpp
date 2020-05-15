#include <iostream>
using namespace std;

int n, m;
int f(int cur, bool right, int size)
{
    if (size == 1)
    {
        return 0;
    }
    int step, l;
    if (right)
    {
        if (m > size - 1 - cur)
        {
            step = (m + cur) % (2 * size - 2);
            l = (step == 0 ? 2 * size - 3 : step - 1);
            if (l < size - 1)
                right = 0;
            else
                l = 2 * size - 2 - l, right = 1;
        }
        else
        {
            step = cur + m;
            l = step - 1;
            if (l == size - 1)
                right = 1;
            else
                right = 0;
        }
    }
    else
    {
        if (m > cur)
        {
            step = (m - cur) % (2 * size - 2);
            l = (step == 0 ? 2 * size - 3 : step - 1);
            if (l < size - 1)
                right = 0;
            else
                l = 2 * size - 2 - l, right = 1;
        }
        else
        {
            step = cur - m;
            l = step + 1;
            if (l == 0)
                right = 0;
            else
                right = 1;
        }
    }
    if (l == 0)
        return 1 + f(0, 1, size - 1);
    else if (l == size - 1)
        return f(size - 2, 0, size - 1);
    else
    {
        int pos;
        if (!right)
            pos = f(l, (l == size - 2 ? 0 : 1), size - 1);
        else
            pos = f(l - 1, (l == 1 ? 1 : 0), size - 1);
        if (pos >= l)
            ++pos;
        return pos;
    }
}

int main()
{
    cin >> n >> m;

    cout << f(0, true, n) + 1 << endl;

    return 0;
}