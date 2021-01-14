#include <iostream>
using namespace std;
struct node
{
    int lchild = -1, rchild = -1;
};
node a[1000005];
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

int main()
{
    int n, root;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> root;
        if (a[root].lchild == -1)
            a[root].lchild = i;
        else
            a[root].rchild = i;
    }

    bool flag = true;
    myquene<int> q;

    int t = 0;
    while (t != -1)   //最后进入节点并不一定最大
    {
        q.enQueue(a[t].lchild);
        q.enQueue(a[t].rchild);
        t = q.getHead();
        q.deQueue();
    }
    while (!q.isEmpty())
    {
        t = q.getHead();
        q.deQueue();
        if (t != -1)
            flag = false;
    }

    if (flag)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}