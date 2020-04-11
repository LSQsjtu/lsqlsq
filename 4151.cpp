#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N, currentNum = 0;
    cin >> T;
    while(T>0)
    {
        T--;
        bool flag = true;
        cin >> N;
        int myStackTop = 0;
        for (int i = 0, max = 1; i < N; i++)
        {
            cin >> currentNum;
            if (!flag)
                continue;
            if (max <= currentNum)
            {
                myStackTop = currentNum;
                max = currentNum + 1;
            }
            if (currentNum <= myStackTop)
                myStackTop = currentNum;
            else
            {
                flag = false;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}