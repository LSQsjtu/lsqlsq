#include <cstdio>

const int BuckSize = 300;
int n, m;

class node
{
public:
    int len;
    int data[BuckSize];
    node *next;
    node(node *q = nullptr) : next(q)
    {
        len = 0;
    }

    void split(int pos)
    {
        if (pos < 0 || pos >= len)
        {
            return;
        }
        node *b = new node(next);
        next = b;
        b->len = len - pos;
        for (int i = 0; i < len - pos; ++i)
            b->data[i] = data[i + pos];
        len = pos;
    }
    void merge()
    {
        node *b = next;
        if (b != nullptr && len + b->len < BuckSize)
        {
            next = b->next;
            for (int i = 0; i < b->len; ++i)
                data[len++] = b->data[i];
            delete b;
        }
    }
};

node *head = new node;

void insert(int x, int y)
{
    node *p = head->next;
    while (p && x > p->len)
    {
        x -= p->len;
        p = p->next;
    }
    p->split(x);
    p->data[p->len++] = y;
}

void remove(int x)
{
    node *p = head->next;
    while (p && x > p->len)
    {
        x -= p->len;
        p = p->next;
    }
    p->split(x);
    --p->len;
}

int main()
{
    scanf("%d%d", &n, &m);
    node *p = head->next = new node();
    int t, op;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &t);
        p->data[p->len++] = t;
        if (p->len == BuckSize)
        {
            p->next = new node();
            p = p->next;
        }
    }
    while (m--)
    {
        scanf("%d", &op);
        int x, y;
        if (op == 1)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
        }
        else
        {
            scanf("%d", &x);
            remove(x);
        }
        node *p = head->next;
        while (p)
        {
            p->merge();
            p = p->next;
        }
    }
    p = head->next;
    while (p)
    {
        for (int i = 0; i < p->len; ++i)
            printf("%d ", p->data[i]);
        p = p->next;
    }
    printf("\n");
    return 0;
}