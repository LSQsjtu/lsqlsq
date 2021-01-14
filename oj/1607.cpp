#include <iostream>
using namespace std;
 
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
 
struct node
{
    long long id;
    myquene<int> naive;
    node *next = 0;
};
int a[2000000]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, k, j = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    node *head, num;
    head = &num;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        if (k == 0)//oj上只能判断0
        {
            if (j >= n)
            {
                continue;
            }
            node *p = head;
            while (p->next != 0)
            {
                if (p->id == a[j])
                {
                    p->naive.enQueue(j + 1);
                    break;
                }
                p = p->next;
            }
            if (p->next == 0)
            {
                p->next = new node;
                p->id = a[j];
                p->naive.enQueue(j + 1);
            }
            j++;
        }
        else
        {
            if (head->naive.isEmpty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << head->naive.deQueue() << '\n';
                if (head->naive.isEmpty())
                {
                    head = head->next;
                }
            }
        }
    }
 
    return 0;
}