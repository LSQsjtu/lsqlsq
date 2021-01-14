#include <cstdio>
#include <cstring>

char str[100010];
int n, temp;
struct node
{
    int l, r, x, lazy;
} data[30][400010];
void build(int l, int r, int k, int op)
{

    data[op][k].l = l;
    data[op][k].r = r;
    data[op][k].x = 0;
    data[op][k].lazy = -1;
    if (l == r)
        return;

    int mid = (l + r) / 2;
    build(l, mid, k * 2, op);
    build(mid + 1, r, k * 2 + 1, op);
}

void pushdown(int k, int op)
{
    if (data[op][k].lazy == -1)
        return;
    if (data[op][k].l == data[op][k].r)
        return;

    if (data[op][k].lazy == 0)
    {
        data[op][k * 2].x = data[op][k * 2].lazy = 0;
        data[op][k * 2 + 1].x = data[op][k * 2 + 1].lazy = 0;
    }
    else
    {
        data[op][k * 2].x = data[op][k * 2].r - data[op][k * 2].l + 1;
        data[op][k * 2 + 1].x = data[op][k * 2 + 1].r - data[op][k * 2 + 1].l + 1;
        data[op][k * 2].lazy = data[op][k * 2 + 1].lazy = 1;
    }
    data[op][k].lazy = -1;
}

void modify(int l, int r, int k, int op)
{

    if (data[op][k].l == l && data[op][k].r == r)
    {
        data[op][k].x = data[op][k].r - data[op][k].l + 1;
        data[op][k].lazy = 1;
        return;
    }

    pushdown(k, op);

    int mid = (data[op][k].l + data[op][k].r) / 2;

    if (r <= mid)
        modify(l, r, k * 2, op);
    else if (l > mid)
        modify(l, r, k * 2 + 1, op);
    else
    {
        modify(l, mid, k * 2, op);
        modify(mid + 1, r, k * 2 + 1, op);
    }

    data[op][k].x = data[op][k * 2].x + data[op][k * 2 + 1].x;
}

void search(int l, int r, int k, int op)
{

    if (data[op][k].l == l && data[op][k].r == r)
    {
        temp += data[op][k].x;

        data[op][k].lazy = 0;
        return;
    }

    pushdown(k, op);

    int mid = (data[op][k].l + data[op][k].r) / 2;

    if (r <= mid)
        search(l, r, k * 2, op);
    else if (l > mid)
        search(l, r, k * 2 + 1, op);
    else
    {
        search(l, mid, k * 2, op);
        search(mid + 1, r, k * 2 + 1, op);
    }

    data[op][k].x = data[op][k * 2].x + data[op][k * 2 + 1].x;
}
void init()
{
    int i;
    scanf("%s", str);
    for (i = 0; i < 26; i++)
        build(1, n, 1, i);
    for (i = 0; i < n; i++)
        modify(i + 1, i + 1, 1, str[i] - 'a');
}
int main()
{
    int m, a, b, c, i, j, k;
    int mark[30];
    scanf("%d%d", &n, &m);
    init();

    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        memset(mark, 0, sizeof(mark));
        for (i = 0; i < 26; i++)
        {
            temp = 0;
            search(a, b, 1, i); // 查找区间内i字母出现的次数，并清空
            mark[i] += temp;
        }
        if (c == 0)
        {
            k = a;
            for (i = 25; i >= 0; i--)
                if (mark[i] != 0)
                {
                    modify(k, k + mark[i] - 1, 1, i); // 更新区间字母
                    k += mark[i];
                }
        }
        else
        {
            k = a;
            for (i = 0; i < 26; i++)
                if (mark[i] != 0)
                {
                    modify(k, k + mark[i] - 1, 1, i);
                    k += mark[i];
                }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 26; j++)
        {
            temp = 0;
            search(i, i, 1, j);
            if (temp != 0)
            {
                printf("%c", j + 'a');
                break;
            }
        }
    }
    printf("\n");
    return 0;
}