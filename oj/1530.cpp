#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char ans[1000000];
int strindex;

template <class T>
class myBinaryTree
{
public:
    struct node
    {
        T data;
        node *lchild = NULL, *rchild = NULL;
    };
    node *root = NULL;
    node **nodeList = NULL;
    long long sizeOfTree = 0;
    void createNode(int nodeNum, int lchild, int rchild, T data)
    {
        if (nodeList[nodeNum] == 0)
            nodeList[nodeNum] = new node;

        nodeList[nodeNum]->data = data;

        if (lchild != 0)
        {
            if (nodeList[lchild] == NULL)
                nodeList[lchild] = new node;
            nodeList[nodeNum]->lchild = nodeList[lchild];
        }

        if (rchild != 0)
        {
            if (nodeList[rchild] == NULL)
                nodeList[rchild] = new node;
            nodeList[nodeNum]->rchild = nodeList[rchild];
        }
    }
    void createTree(T *treeData, int num)
    {
        sizeOfTree = num;
        nodeList = new node *[num + 1] { NULL };
        for (int i = 1; i <= num; i++)
        {
            int lchild = i * 2 <= num ? i * 2 : 0,
                rchild = i * 2 + 1 <= num ? i * 2 + 1 : 0;
            createNode(i, lchild, rchild, treeData[i - 1]);
        }
        root = nodeList[1];
    }
    void clear()
    {
        clear(root);
    }

    void clear(node *&p)
    {
        if (p == NULL)
            return;
        clear(p->lchild);
        clear(p->rchild);
        delete p;
        p = NULL;
    }
    ~myBinaryTree()
    {
        clear(root);
    }
    bool empty()
    {
        return root == NULL;
    }
    void preOrder() const
    {
        preOrder(root);
    }
    void preOrder(node *t) const
    {
        if (t == NULL)
            return;
        cout << t->data;
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
    void postOrder() const
    {
        postOrder(root);
    }
    void postOrder(node *t) const
    {
        if (t == NULL)
            return;
        postOrder(t->lchild);
        postOrder(t->rchild);
        cout << t->data;
    }
    void midOrder() const
    {
        midOrder(root);
    }
    void midOrder(node *t) const
    {
        if (t == NULL)
            return;
        midOrder(t->lchild);
        cout << t->data;
        midOrder(t->rchild);
    }
};
void dMidOrder(char *str, int len, int pos)
{
    if (pos > len)
    {
        return;
    }

    dMidOrder(str, len, 2 * pos);
    ans[pos - 1] = str[strindex];
    strindex++;
    dMidOrder(str, len, 2 * pos + 1);
}

void dPreOrder(char *str, int len, int pos)
{
    if (pos > len)
    {
        return;
    }

    ans[pos - 1] = str[strindex];
    strindex++;
    dPreOrder(str, len, 2 * pos);
    dPreOrder(str, len, 2 * pos + 1);
}

void dPostOrder(char *str, int len, int pos)
{
    if (pos > len)
    {
        return;
    }

    dPostOrder(str, len, 2 * pos);
    dPostOrder(str, len, 2 * pos + 1);
    ans[pos - 1] = str[strindex];
    strindex++;
}
int main()
{
    int num;
    cin >> num;

    for (; num > 0; num--)
    {
        int n;
        scanf("%d", &n);
        char order[20], operat[20], *str = new char[n + 1];
        scanf("%s %s\n%s", order, operat, str);
        //建树
        myBinaryTree<char> Tree;
        if (strcmp(operat, "ENCODE") == 0)
        {
            Tree.createTree(str, n);
            delete str;
            if (strcmp(order, "PREORDER") == 0)
                Tree.preOrder();
            else if (strcmp(order, "INORDER") == 0)
                Tree.midOrder();
            else if (strcmp(order, "POSTORDER") == 0)
                Tree.postOrder();
        }
        else if (strcmp(operat, "DECODE") == 0)
        {
            int i = 0;
            if (strcmp(order, "PREORDER") == 0)
            {
                strindex = 0;
                dPreOrder(str, n, 1);
                ans[n] = '\0';
                cout << ans;
            }
            else if (strcmp(order, "INORDER") == 0)
            {
                strindex = 0;
                dMidOrder(str, n, 1);
                ans[n] = '\0';
                cout << ans;
            }
            else if (strcmp(order, "POSTORDER") == 0)
            {
                strindex = 0;
                dPostOrder(str, n, 1);
                ans[n] = '\0';
                cout << ans;
            }
            delete str;
        }
        printf("\n");
    }

    return 0;
}