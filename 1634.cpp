#include <cstdio>
int heapBuild(int a[],int root,int len)
{
int lchild=2*root+1;
if(lchild<len)
{
    int max=lchild,rchild=lchild+1;
}
}

int heapSort(int a[],int len)
{

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

int quickSort(int s[], int l, int r)
{
    int sum = 0;
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
            {
                sum++;
                j--;
            }
            if (i < j)
            {
                sum++;
                s[i++] = s[j];
            }
            while (i < j && s[i] <= x) // 从左向右找第一个大于x的数
            {
                sum++;
                i++;
            }
            if (i < j)
            {
                sum++;
                s[j--] = s[i];
            }
        }
        s[i] = x;
        sum += quickSort(s, l, i - 1);
        sum += quickSort(s, i + 1, r);
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
        /* code */
        break;
    case 2:
        printf("%d\n", mergeSort(a, 0, n - 1));
        break;
    case 3:
        printf("%d\n", quickSort(a, 0, n - 1));
        break;
    default:
        break;
    }
}