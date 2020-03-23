#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr;
    arr = new int[n + 1];
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        arr[i] = 0;
        arr[i] += arr[i - 1];
        for (int j = 1; j < i; ++j)
        {
            arr[i] += arr[j - 1] * arr[i - j - 1];
            arr[i] %= 19301; //防止整数过大，超过int范围
        }
    }
    cout << arr[n] << endl;
    return 0;
}