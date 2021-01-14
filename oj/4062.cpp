#include <iostream>
using namespace std;
long long z = 0;
void f(long long a, long long b)
{
    if (a == 0 || b == 0)
        return;
    if (a >= b)
    {
        z += b * 4;
        a -= b;
    }
    else
    {
        z += a * 4;
        b -= a;
    }
    f(a, b);
}
int main()
{
    long long m, n;
    cin >> m >> n;
    f(m, n);
    cout << z << endl;
    return 0;
}
