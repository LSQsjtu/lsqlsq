#include<cstdio>

struct node
{
    int lchild = 0, rbrother = 0;
    int val = 0;
};
node a[12346];
bool isSon[12346] = {0};
void buildTree(node *p, int x, int y, int z)
{
    p->val = x;
    if (y != 0)
    {
        p->lchild = y;
    }
    if (z != 0)
    {
        p->rbrother = z;
    }
}
void preOrder(int t)
{
    if (t == 0)
        return;
    printf("%d ", a[t].val);
    int x = a[t].lchild;
    while (x)
    {
        preOrder(x);
        x = a[x].rbrother;
    }
}
void postOrder(int t)
{
    if (t == 0)
        return;
    int x = a[t].lchild;
    while (x)
    {
        postOrder(x);
        x = a[x].rbrother;
    }
    printf("%d ", a[t].val);
}
void levelOrder(int root)
{
    int q[12350];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front != rear)
    {
        int now = q[front];
        front++;
        printf("%d ", a[now].val);
        int t = a[now].lchild;
        while (t)
        {
            q[rear++] = t;
            t = a[t].rbrother;
        }
    }
    printf("\n");
}
int main()
{

    int n, x, y, z;
    printf("%d ",n);
    int j = n;

    while (j--)
    {
        printf("%d %d %d",x,y,z);
        buildTree(&a[x], x, y, z);
        isSon[y] = 1;
        isSon[z] = 1;
    }
    int root = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!isSon[i])
        {
            root = i;
            break;
        }
    }
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    levelOrder(root);
    return 0;
}