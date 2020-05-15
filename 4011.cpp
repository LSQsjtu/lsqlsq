#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const long long p = 1e10;
int k, h;
class bigInt
{
    long long num[10] = {0};
    int len;

public:
    bigInt()
    {
        len = 1;
    }
    bigInt(int x)
    {
        len = 0;
        while (x != 0)
        {
            num[len++] = x % p;
            x /= p;
        }
    }
    friend bigInt operator+(const bigInt &a, const bigInt &b)
    {
        long long c = 0;
        bigInt r;
        r.len = max(a.len, b.len);
        for (int i = 0; i < r.len; ++i)
        {
            r.num[i] = a.num[i] + b.num[i] + c;
            c = r.num[i] / p;
            r.num[i] %= p;
        }
        if (c > 0)
            r.num[r.len++] = c;
        return r;
    }
    bigInt &operator=(const bigInt &a)
    {
        memset(num, 0, sizeof(num));
        len = a.len;
        for (int i = 0; i < a.len; ++i)
            num[i] = a.num[i];
        return *this;
    }
    friend ostream &operator<<(ostream &os, const bigInt &a)
    {
        os.fill('0');
        os << a.num[a.len - 1];
        for (int i = a.len - 2; i >= 0; --i)
        {
            os << setw(10) << a.num[i];
        }
        return os;
    }
};
bigInt x[50][50];
int main()
{
    cin >> k >> h;
    for (int i = 0; i <= k - 1; ++i)
        x[1][i] = k - i;
    for (int i = 2; i <= h - 1; ++i)
    {
        for (int j = 0; j <= k - 1; ++j)
            for (int l = 0; l < k - j; ++l)
                x[i][j] = x[i][j] + x[i - 1][l];//第二层k个节点下分别有多少叶节点
    }
    cout << x[h - 1][0];
    return 0;
}