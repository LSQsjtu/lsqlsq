#include <iostream>
#include <iomanip>
using namespace std;
int boyTime[1000005], girlTime[1000005];
template <class T>
class myquene
{
public:
    T *data;
    int maxSize;
    int front, rear;
    void doubleSpace()
    {
        T *tmp = data;
        data = new T[maxSize * 2];

        for (int i = 1; i <= maxSize; i++)
        {
            data[i] = tmp[(front + i) % maxSize];
        }
        front = 0;
        maxSize *= 2;
        delete tmp;
    }
    myquene(int size = 10)
    {
        maxSize = size;
        data = new T[size];
        front = rear = 0;
    }
    ~myquene() { delete[] data; }
    void enQueue(const T &x)
    {
        if ((rear + 1) % maxSize == front)
        {
            doubleSpace();
        }
        rear = (rear + 1) % maxSize;
        data[rear] = x;
    }
    T deQueue()
    {
        front = (front + 1) % maxSize;
        return data[front];
    }
    T getHead() const
    {
        return data[(front + 1) % maxSize];
    }
    bool isEmpty() { return front == rear; }
};

void quickSort(int s[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); //加速输出

    int n, m, boynum = 0, girlnum = 0, currentTime = 0, currentSong = 0, *a;
    double boyWait = 0, girlWait = 0;
    myquene<int> boy, girl;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int sex, time;
        cin >> sex >> time;
        if (sex == 1)
        {
            boyTime[boynum] = time;
            boynum++;
        }
        else
        {
            girlTime[girlnum] = time;
            girlnum++;
        }
    }
    quickSort(boyTime, 0, boynum - 1);
    quickSort(girlTime, 0, girlnum - 1);

    for (int i = 0; i < boynum; i++)
    {
        boy.enQueue(boyTime[i]);
    }
    for (int i = 0; i < girlnum; i++)
    {
        girl.enQueue(girlTime[i]);
    }
    for (;; currentSong++)
    {
        while (!boy.isEmpty() && !girl.isEmpty() && boy.getHead() <= currentTime && girl.getHead() <= currentTime)
        {
            boyWait += currentTime - boy.deQueue();
            girlWait += currentTime - girl.deQueue();
        }
        currentTime += a[currentSong];

        if (currentSong == n - 2)
        {
            while (!boy.isEmpty())
            {
                boyWait += currentTime - boy.deQueue();
            }
            while (!girl.isEmpty())
            {
                girlWait += currentTime - girl.deQueue();
            }
            break;
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(2) << (boyWait / boynum) << ' ' << (girlWait / girlnum);
    delete[] a;
    return 0;
}