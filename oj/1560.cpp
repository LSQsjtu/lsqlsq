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
        node(int x = 0, node *l = 0, node *r = 0)
            : data(x), left(l), right(r) {}
    };

    node *root;
    void erase(int val, node *&ptr);
    void insert(int val, node *&ptr);

public:
    binarySearchTree() : root(0){};
    void insert(int val) { insert(val, root); };
    void erase(int val) { erase(val, root); };

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

void binarySearchTree::insert(int i, node *&ptr)
{
    if (ptr == 0)
        ptr = new node(i);
    else
    {
        if (ptr->data == i)
            return;
        if (ptr->data < i)
            insert(i, ptr->right);
        else
            insert(i, ptr->left);
    }
}

void binarySearchTree::erase(int i, node *&ptr)
{
    if (ptr == 0)
        return;
    if (ptr->data == i)
    {
        if (ptr->right == 0)
            ptr = ptr->left;
        else
        {
            node *find = ptr->right;
            if (find->left == 0)
            {
                find->left = ptr->left;
                delete ptr;
                ptr = find;
            }
            else
            {
                while (find->left->left != 0)
                    find = find->left;
                ptr->data = find->left->data;
                node *tmp = find->left;
                find->left = tmp->right;
                delete tmp;
            }
        }
    }
    else
    {
        if (ptr->data < i)
            erase(i, ptr->right);
        else
            erase(i, ptr->left);
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