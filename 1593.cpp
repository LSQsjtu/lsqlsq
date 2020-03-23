#include <cstdio>
using namespace std;

struct mouse
{
    int number; //编号
    int power;
    int total;
};
void quicksort(mouse *data, int l, int r)
{
    if(l<r)
    {
        int i = l, j = r;
        mouse x = data[l];
        while (i < j)
        {
            while (i < j && (data[j].total < x.total || (data[j].total == x.total && data[j].number > x.number)))
                --j;
            if (i < j)
            {
                data[i] = data[j];
                ++i;
            }
            while (i < j && (data[i].total > x.total || (data[i].total == x.total && data[i].number < x.number)))
                ++i;
            if (i < j)
            {
                data[j] = data[i];
                --j;
            }
        }
        data[i] = x;
        quicksort(data, l, i - 1);
        quicksort(data, i + 1, r);
    }
}
void maopao_sort(mouse *data, int len)
{
    bool flag = false;
    for (int i = 0; i < len - 1; i++)
    {
        flag = true;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (data[j].total < data[j + 1].total)
            {
                mouse temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                flag = false;
            }
            else if ((data[j].total == data[j + 1].total) && (data[j].number > data[j + 1].number))
            {
                mouse temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    mouse *p;
    p = new mouse[2 * n];
    for (int i = 0; i < 2 * n; ++i)
    {
        scanf("%d", &p[i].total);
        p[i].number = i + 1;
    }
    for (int i = 0; i < 2 * n; ++i)
        scanf("%d", &p[i].power);
    quicksort(p, 0, 2 * n - 1);
    for (int j = 0; j < r; ++j)
    {
        for (int i = 0; i < 2 * n; i = i + 2)
        {
            if (p[i].power > p[i + 1].power)
                p[i].total += 2;
            else if (p[i].power == p[i + 1].power)
            {
                p[i].total++;
                p[i + 1].total++;
            }
            else
                p[i + 1].total += 2;
        }
        maopao_sort(p, 2 * n);
    }
    for (int i = 0; i < 2 * n; ++i)
        printf("%d ", p[i].number);
    return 0;
}