//深度搜索
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[20], visit[20] = {0};
int prime[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool isprime(int a)
{
    for (int n : prime)
        if (n == a)
            return true;
    return false;
}
void dfs(int s)
{
    if (s == n)
    {
        if (!isprime(1 + a[n]))
            return;
        for (int i = 1; i < n; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
    }
    else
    {
        for (int i = 2 + (s + 1) % 2; i <= n; i += 2)
        {
            if (!visit[i] && isprime(i + a[s]))
            {
                a[s + 1] = i;
                visit[i] = 1;
                dfs(s + 1);
                visit[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "None" << endl;
    }
    else
    {
        a[1] = 1;
        dfs(1);
    }
    return 0;
}