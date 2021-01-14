#include <iostream>
using namespace std;
int main()
{
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        if (n <= k)
        {
            cout << "5555" << endl;
        }
        else if (k == 1)
        {
            if (n % 2 == 0)
                cout << "Yeah!" << endl;
            else
                cout << "5555" << endl;
        }
        else
            cout << "Yeah!" << endl;
        /**
        * juda面对一条链；如果该链的长度为奇数，那么后手选取最中间的那一点即可，之后与先手进行对称构造；
        * 如果该链的长度为偶数，那么后手应该选取最中间的两点，但是注意k=1的情况需要特殊讨论，之后进行对称构造即可。
        */
    }
    return 0;
}