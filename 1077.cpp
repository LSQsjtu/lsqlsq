#include <iostream>
using namespace std;

int DP[35][35], path[35][35], tree[35] = {0};

int grade(int l, int r)
{
    if (l > r) //某个子树为空，规定其加分为1
    {
        return 1;
    }
    if (l == r)
    {
        DP[l][r] = tree[l];
        path[l][r] = l;
        return tree[l];
    }
    if (DP[l][r] > 0)
    {
        return DP[l][r];
    }
    for (int i = l; i <= r; i++)
    {
        int x = grade(l, i - 1) * grade(i + 1, r) + tree[i];
        if (x > DP[l][r])
        {
            DP[l][r] = x;
            path[l][r] = i; //l到r的根节点
        }
    }
    return DP[l][r];
}

void preOrder(int l, int r)
{
    if (l > r)
    {
        return;
    }
    cout << path[l][r] << ' ';
    preOrder(l, path[l][r] - 1);
    preOrder(path[l][r] + 1, r);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }
    cout << grade(1, n) << '\n';
    preOrder(1, n);

    return 0;
}