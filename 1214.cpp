//孩子兄弟法表示
#include <cstdio>
using namespace std;
struct node
{
    int lchild = 0, rbrother = 0;
    int val = 0;
};
node a[100005];
bool b[100005] = {0};

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
    int q[100005];
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
    int n, root=0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a[i].lchild, &a[i].rbrother, &a[i].val);
        b[a[i].lchild] = true;
        b[a[i].rbrother] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!b[i])
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