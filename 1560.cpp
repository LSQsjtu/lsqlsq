#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

char ans[100009] = {0};

class binarySearchTree
{
private:
    struct node
    {
        int data;
        node *left;
        node *right;
        node *parent = nullptr;
        node(int x = 0, node *l = 0, node *r = 0)
            : data(x), left(l), right(r) {}
    };

    node *root;

public:
    binarySearchTree() : root(0){};
    void insert(int val);
    void erase(int val);

    void find(int val)
    {
        memset(ans, 0, sizeof(ans));
        int len = 0;
        ans[len++] = '*';
        node *p = root;
        while (p)
        {
            if (p->data == val)
            {
                printf("%s\n", ans);
                return;
            }
            else if (val < p->data)
            {
                ans[len++] = 'l';
                p = p->left;
            }
            else
            {
                ans[len++] = 'r';
                p = p->right;
            }
        }
        printf("Nothing.\n");
    }
};

void binarySearchTree::insert(int val)
{
    if (!root)
    {
        root = new node;
        root->data = val;
        return;
    }
    node *p = root;
    while(p)
    {
        if (p->data == val)
            return;
        if (val < p->data)
        {
            if (p->left)
                p = p->left;
            else
            {
                p->left = new node;
                p->left->parent = p;
                p = p->left;
                break;
            }
        }
        else
        {
            if (p->right)
                p = p->right;
            else
            {
                p->right = new node;
                p->right->parent = p;
                p = p->right;
                break;
            }
        }
    }
    p->data = val;
}

void binarySearchTree::erase(int val)
{
    node *p = root;
    while (p)
    {
        if (p->data == val)
        {
            if (p->left == nullptr && p->right == nullptr)
            {
                if (p == root)
                    root = nullptr;
                else if (p->parent->left == p)
                    p->parent->left = nullptr;
                else
                    p->parent->right = nullptr;
                delete p;
            }
            else if (p->left != nullptr && p->right == nullptr)
            {
                if (p == root)
                {
                    root = p->left;
                    p->left->parent = nullptr;
                }
                else if (p->parent->left == p)
                {
                    p->parent->left = p->left;
                    p->left->parent = p->parent;
                }
                else
                {
                    p->parent->right = p->left;
                    p->left->parent = p->parent;
                }
                delete p;
            }
            else if (p->right != nullptr)
            {
                node *q = p->right;
                while (q->left != 0)
                    q = p->left;
                p->data = q->data;
                if (q->parent->left == q)
                    q->parent->left = q->right;
                else
                    q->parent->right = q->right;
                if (q->right)
                    q->right->parent = q->parent;
                delete q;
            }
            return;
        }
        else if (val < p->data)
            p = p->left;
        else
            p = p->right;
    }
}

binarySearchTree bst;

int main()
{
    int q, x;
    char op;
    scanf("%d", &q);
    while (q--)
    {
        scanf("\n%c%d", &op, &x);
        if (op == '+')
        {
            bst.insert(x);
        }
        else if (op == '-')
        {
            bst.erase(x);
        }
        else
        {
            bst.find(x);
        }
    }
    return 0;
}