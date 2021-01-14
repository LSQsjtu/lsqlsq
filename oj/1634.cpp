#include <cstdio>
struct node
{
    node *next = nullptr, *last = nullptr;
    int data = 0;
};

int push(int a[], int now)
{
    int sum = 0;
    while (now > 0)
    {
        ++sum;
        if (a[now] < a[(now - 1) / 2])//向上过滤
        {
            int tmp = a[now];
            a[now] = a[(now - 1) / 2];
            a[(now - 1) / 2] = tmp;
            now = (now - 1) / 2;
        }
        else
            break;
    }
    return sum;
}
int pop(int a[], int length)
{
    int sum = 0;
    a[0] = a[length];
    int hole = 0;
    while (2 * hole + 1 < length)
    {
        int child = 2 * hole + 1;
        if (2 * hole + 2 < length)
        {
            ++sum;
            if (a[2 * hole + 2] < a[2 * hole + 1])
                ++child;
        }
        ++sum;
        if (a[child] < a[hole])
        {
            int tmp = a[child];
            a[child] = a[hole];
            a[hole] = tmp;
            hole = child;
        }
        else
            break;
    }
    return sum;
}
int heapSort(int a[], int len)
{
    int sum = 0;
    int *heapdata = new int[len];
    for (int i = 0; i < len; ++i)
    {
        heapdata[i] = a[i];
        sum += push(heapdata, i);
    }
    for (int i = 0; i < len; ++i)
    {
        sum += pop(heapdata, len - i - 1);
    }
    return sum;
}

int merge(int *arr, int l, int mid, int r)
{
    int sum = 0;
    int *newarr = new int[r - l + 1];
    int p1 = l, p2 = mid + 1, i = 0;
    while (p1 <= mid && p2 <= r)
    {
        newarr[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++]; //取较小者并移动指针
        sum++;
    }
    while (p1 <= mid)
        newarr[i++] = arr[p1++];
    while (p2 <= r)
        newarr[i++] = arr[p2++];

    for (int i = 0; i < r - l + 1; i++)
    {
        arr[l + i] = newarr[i];
    }

    delete[] newarr;
    return sum;
}
int mergeSort(int *a, int l, int r)
{
    int sum = 0;
    if (l < r)
    {
        int m = (l + r - 1) / 2;
        sum += mergeSort(a, l, m);
        sum += mergeSort(a, m + 1, r);
        sum += merge(a, l, m, r);
    }
    return sum;
}

long long quickSort(int s[], int len)
{
    long long sum = 0;
    node *root = new node[len + 2];
    for (int i = 1; i <= len + 1; i++)
    {
        root[i - 1].next = &root[i];
        root[i].last = &root[i - 1];
        root[i].data = i;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        sum += root[s[i]].next->data - root[s[i]].last->data - 2;
        root[s[i]].last->next = root[s[i]].next;
        root[s[i]].next->last = root[s[i]].last;
    }

    return sum;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    switch (k)
    {
    case 1:
        printf("%d\n", heapSort(a, n));
        break;
    case 2:
        printf("%d\n", mergeSort(a, 0, n - 1));
        break;
    case 3:
        printf("%lld\n", quickSort(a, n));
        break;
    default:
        break;
    }
}