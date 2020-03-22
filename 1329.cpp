#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t, m, n;
    char c;
    cin >> t;
    c = cin.get();
    for (int i = 0; i < t; ++i)
    {
        int *like, *dislike, k;
        c = cin.get();
        cin >> n >> m;
        like = new int[m];
        dislike = new int[m];
        for (int i = 0; i < m; ++i)
        {
            like[i] = dislike[i] = 0;
            do
            {
                cin >> k;
                c = cin.get();
                if (k > 0)
                {
                    like[i] += pow(2, k - 1); //位上一表示喜欢
                }
                else
                {
                    dislike[i] += pow(2, -k - 1); //位上一表示不喜欢
                }
            } while (c != '\n');
        }
        bool flag;
        for (int j = 0; j < pow(2, n) - 1; ++j) //j位上一表示选了这道菜
        {
            flag = 1;
            for (int i = 0; i < m; ++i)
            {
                if ((j & like[i]) == 0 && ((~j) & dislike[i]) == 0)
                    flag = 0;
            }
            if (flag)
            {
                cout << "Bingo!" << endl;
                break;
            }
        }
        if (!flag)
            cout << "Sigh..." << endl;
    }
    return 0;
}