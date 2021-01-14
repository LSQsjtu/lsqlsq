#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;

int n, m, tot = 0;
char s[10002] = {'\0'};
int lis[15], len[1000001];
ll *sufHash1[1000001];

void sufHash(char *str, ll *preHash, int len)
{
    preHash[1] = str[len - 1] - 'a' + 1;
    for (int i = 1; i < len; i++)
    {
        preHash[i + 1] = 7 * preHash[i] + (str[len - i - 1] - 'a');
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        len[i] = strlen(s);
        sufHash1[i] = new ll[len[i] + 1];
        sufHash(s, sufHash1[i], len[i]);
    }
    while (m--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            scanf("%s", s);
            len[++n] = strlen(s);
            sufHash1[n] = new ll [len[n] + 1];
            sufHash(s, sufHash1[n], len[n]);
        }
        else
        {
            int t, Min = 10005;
            cin >> t;

            for (int i = 1; i <= t; ++i)
                cin >> lis[i], Min = min(Min, len[lis[i]]);
            int l = 0, r = Min;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                bool flag = true;
                ll targ = sufHash1[lis[1]][mid];
                for (int i = 2; i <= t; ++i)
                    if (sufHash1[lis[i]][mid] != targ)
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                    l = mid;
                else
                    r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}