#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

const int mod = 1e6;

int calhash(char s[])
{
    int len = strlen(s);
    ll ret = 0;
    for (int i = 0; i <= len; i++)
    {
        ret = 31 * ret + s[i] - 'a';
    }
    return ret % mod;
}

int m, n, sum = 0, ans = 1e6;
int s[1001], appear[mod], search[100005] = {0};
bool isExist[mod] = {0}, pos[mod] = {0};

int main()
{
    cin >> n;
    char temp[11];
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        s[i] = calhash(temp);
        pos[s[i]] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> temp;
        search[i] = calhash(temp);
        if (pos[search[i]] && !isExist[search[i]])
        {
            isExist[search[i]] = true;
            ++sum;
        }
    }
    cout << sum << endl;
    if (sum==0)
    {
        cout<<'0'<<endl;
        return 0;
    }
    
    int l = 1, r = 1;
    while (1)
    {
        if (sum > 0)
        {
            if (r > m)
                break;
            if (pos[search[r]])
            {
                if (!appear[search[r]])
                    sum--;
                appear[search[r]]++;
            }
            r++;
        }
        else
        {
            while (!pos[search[l]])
                l++;
            if (l > m)
                break;
            ans = min(ans, r - l);
            if (appear[search[l]] == 1)
                sum++;
            if (appear[search[l]] >= 1)
                appear[search[l]]--, l++;
        }
    }
    cout << ans << endl;
    return 0;
}
//尺取法通常是对数组保存一对下标，即所选取的区间的左右端点，然后根据实际情况不断地推进区间左右端点以得出答案。