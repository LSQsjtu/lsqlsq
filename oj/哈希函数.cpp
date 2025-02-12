#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int maxN = 1e5 + 10;
string str[maxN];
int preHashpos[maxN] = {0};
ll strHash[maxN], preHash1[maxN] = {0}, sufHash1[maxN] = {0};

ll calHash(string str, int l, int r)
{
    ll ans = 0;
    for (int i = l; i < r; i++)
    {
        ans = 31 * ans + (str[i] - 'a' + 1);
    }
    return ans;
}

void preHash(string str, ll *preHash)
{
    preHash[0] = str[0] - 'a' + 1;
    for (int i = 1; i < str.length(); i++)
    {
        preHash[i] = 31 * preHash[i - 1] + (str[i] - 'a' + 1);
    }
}

void sufHash(string str, ll *preHash)
{
    int len = str.length();
    preHash[0] = str[len - 1] - 'a' + 1;
    for (int i = 1; i < len; i++)
    {
        preHash[i] = 131 * preHash[i - 1] + (str[len - i - 1] - 'a' + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, order, x, y;

    cin >> N;
    str[0] = "";
    for (int i = 1; i <= N; i++)
    {
        cin >> str[i];
        strHash[i] = calHash(str[i], 0, str[i].length());
        preHashpos[i] = preHashpos[i - 1] + str[i - 1].length();
        preHash(str[i], &preHash1[preHashpos[i]]);
        sufHash(str[i], &sufHash1[preHashpos[i]]);
    }

    cin >> M;
    while (M--)
    {
        cin >> order;
        switch (order)
        {
        case 1:
        {
            cin >> x;
            bool flag = 0;
            for (int i = 1; i < x; i++)
            {
                if (strHash[i] == strHash[x])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
            break;
        }
        case 2:
        {
            cin >> x >> y;
            int len1 = str[x].length(), len2 = str[y].length(),
                len3 = len1 < len2 ? len1 : len2;
            int l = 0, r = len3 - 1, ans;
            ll *temp1 = &preHash1[preHashpos[x]],
               *temp2 = &preHash1[preHashpos[y]];
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (temp1[mid] == temp2[mid])
                {
                    ans = mid + 1;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << ans << '\n';
            break;
        }
        case 3:
        {
            cin >> x >> y;
            int len1 = str[x].length(), len2 = str[y].length(),
                len3 = len1 < len2 ? len1 : len2;
            int l = 0, r = len3 - 1, ans;
            ll *temp1 = &sufHash1[preHashpos[x]],
               *temp2 = &sufHash1[preHashpos[y]];
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (temp1[mid] == temp2[mid])
                {
                    ans = mid + 1;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << ans << '\n';
            break;
        }
        }
    }
    return 0;
}