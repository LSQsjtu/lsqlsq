#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    double *a, *f, ave;
    cin >> n;
    a = new double[n];
    f = new double[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ave = a[0];
    f[0] = 1;
    for (int i = 1; i < n; i++)
    {
        f[i] = a[i - 1] * (f[i - 1] + 2) + 1 - a[i - 1]; //如果造成伤害，第(i+1)枪造成的伤害的期望
        ave += a[i]*f[i];
    }
    cout << fixed << setprecision(6) << ave;
    return 0;
}