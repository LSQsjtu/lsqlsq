#include <cstdio>

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

    int sum;
    node *root;
    void insert(int x, node *&t);
    void erase(int x, node *&t);

public:
    binarySearchTree() : root(0), sum(0){};
    void insert(int x) { insert(x, root); };
    void erase(int x) { erase(x, root); };
    int findMin(int x);
};

void binarySearchTree::insert(int x, node *&t)
{
    if (t == 0)
    {
        t = new node(x);
        sum++;
    }
    else if (x < t->data)
    {
        insert(x, t->left);
    }
    else
    {
        insert(x, t->right);
    }
}

void binarySearchTree::erase(int x, node *&t)
{
    if (t == 0)
        return;
    if (x < t->data)
        erase(x, t->left);
    else if (x > t->data)
        erase(x, t->right);
    else if (t->left != 0 && t->right != 0)
    {
        node *p = t->right;
        while (p->left != 0)
            p = p->left;
        t->data = p->data;
        erase(t->data, t->right);
    }
    else
    {
        node *oldNode = t;
        t = (t->left != 0) ? t->left : t->right;
        delete oldNode;
        sum--;
    }
}

int binarySearchTree::findMin(int x)
{
    int ans = 200000000;
    node *n = root;

    while (n != 0)
    {
        if (x < n->data)
        {
            ans = (n->data - x) > ans ? ans : (n->data - x);
            n = n->left;
        }
        else if (x > n->data)
        {
            ans = (x - n->data) < ans ? (x - n->data) : ans;
            n = n->right;
        }
        else
        {
            return 0;
        }
    }

    return ans;
}
int main()
{
    int m;
    scanf("%d", &m);
    binarySearchTree tree;
    while (m--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        switch (x)
        {
        case 0:
            printf("%d\n", tree.findMin(y));
            break;
        case 1:
            tree.insert(y);
            break;
        case 2:
            tree.erase(y);
            break;
        default:
            break;
        }
    }

    return 0;
}