#include <cstdio>
using namespace std;
int main()
{
    int n, *a;
    while (scanf("%d", &n) != -1)
    {
        int time = 0, change = 0;
        a = new int[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            if (a[i] == i)
                a[i] = -1;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == -1)
                continue;
            int length = 0, begin = i, x;
            do
            {
                length++;
                x = a[i];
                a[i] = -1;
                i = x;
            } while (x != begin);
            change += length - 1;
            if (time == 2)//标记已经交换过的元素，交换（已经交换过的元素）的两边得到一个二元素链，并且都被标记
                continue;
            time = (length > 2) ? 2 : 1;
        }
        delete[] a;
        printf("%d\n%d\n", change, time);
    }
    return 0;
}