#include <iostream>
using namespace std;
int len = 0;
bool test(char *a, char *b, int j)
{
    bool flag = 1;
    int k;
    for (int i = 1; i < len; ++i)
    {
        if ((i + 1) % j == 0)
            k = len / j * (j - 1) + (i + 1) / j - 1;
        else
            k = len / j * ((i + 1) % j - 1) + (i + 1) / j;
        if (a[i] != b[k])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    char a[101], b[101];
    int j;
    while ((a[len] = cin.get()) != '\n')
        ++len;
    for (int i = 0; i < len; ++i)
        cin >> b[i];
    for (j = 1; j < len; ++j)
    {
        while (j<len&&b[1] != a[j])
            ++j;
        if (j == len)break;
        if (len % j == 0)
            if (test(a, b, j))
                break;
    }
    if (j == len)
        cout << "No Solution" << endl;
    else
        cout << j << endl;
    return 0;
}