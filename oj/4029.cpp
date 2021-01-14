#include <cstdio>
int main()
{
    int m, n, *a, *sum, max = 0; //n件商品,m特殊要求的顾客
    scanf("%d", &n);
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    sum = new int[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sum[i]);
        if (max < sum[i])
            max = sum[i];
    }
    bool *test = new bool[max + 1];
    /**
     * 在栈中内存小，用堆申请，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数）
     * 堆的大小受限于计算机系统中有效的虚拟内存，因此堆的大小一般都比较大
     * 静态存储区分配内存空间，因此大小自然受限于静态存储区的大小，也叫做BSS（Block Started by Symbol）,在汇编语言中，我么也称之为数据段
     * */
    test[0] = 1;
    for (int i = 1; i <= max; i++)
    {
        test[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (i < a[j])
                continue;
            if (test[i - a[j]])
            {
                test[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (test[sum[i]])
            printf("YES\n");
        else
            printf("NO\n");
    }
    delete[] a;
    delete[] sum;
    return 0;
}