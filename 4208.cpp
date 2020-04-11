#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double a, b, x1, x2, y1, y2;
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;
        int m1 = floor((x1 + y1) / a / 2.0) - floor((x2 + y2) / a / 2.0);
        int m2 = floor((x1 - y1) / b / 2.0) - floor((x2 - y2) / b / 2.0);
        if (abs(m1) > abs(m2))
        {
            cout << abs(m1) << endl;
        }
        else
        {
            cout << abs(m2) << endl;
        }
    }
    return 0;
}