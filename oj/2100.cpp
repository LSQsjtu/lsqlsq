#include <iostream>
#include <cstdio>
using namespace std;
long long a[50005],currentsize=0;

void push(long long in)
{
    int now =++currentsize;
    while (now != 1 && a[now / 2] > in)
    {
        a[now] = a[now / 2];
        now >>= 1;
    }
    a[now] = in;
}
long long pop()
{
    int z = a[1];
    long long change = a[currentsize--];
    int temp = 1;
    while (temp <= currentsize)
    {
        bool flag;
        if (2 * temp + 1 <= currentsize)
        {
            flag = a[2 * temp] < a[2 * temp + 1];
        }
        else
        {
            if (2 * temp <= currentsize)
            {
                flag = true;
            }
            else
            {
                a[temp] = change;
                break;
            }
        }
        if (flag)
        {
            if (change > a[2 * temp])
            {
                a[temp] = a[2 * temp];
                temp <<= 1;
                continue;
            }
            else
            {
                a[temp] = change;
                break;
            }
        }
        else
        {
            if (change > a[2 * temp + 1])
            {
                a[temp] = a[2 * temp + 1];
                temp = temp * 2 + 1;
                continue;
            }
            else
            {
                a[temp] = change;
                break;
            }
        }
    }
    return z;
}

long long cal(int len)
{
    long long sum = 0, min1, min2;
    for (int i = 0; i < len - 1; ++i)
    {
        min1 = pop();
        min2 = pop();
        sum += min1 + min2;
        push(min1 + min2);
    }
    return sum;
}


int main()
{
    long long  n,x;
    scanf("%lld", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &x);
        push(x);
    }

    printf("%lld", cal(n));
    return 0;
}