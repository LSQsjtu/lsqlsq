#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    int n, i, j, circuit, var = 0;

    cin >> n;
    int a[n][n];
    for (circuit = 0; circuit < n / 2; ++circuit)
    {
        for (i = j = circuit; j < n - circuit - 1; ++j)
        {

            a[i][j] = ++var;
        }
        for (; i < n - circuit - 1; ++i)
        {
            a[i][j] = ++var;
        }
        for (; j > circuit; --j)
        {
            a[i][j] = ++var;
        }
        for (; i > circuit; --i)
        {
            a[i][j] = ++var;
        }
    }
    if (n % 2 == 1)
        a[(n - 1) / 2][(n - 1) / 2] = ++var;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(6) << a[i][j];
        cout << endl;
    }

    return 0;
}