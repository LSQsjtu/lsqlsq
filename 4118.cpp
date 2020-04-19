#include <cstdio>
#include <cstring>
template <class T>
class Stack
{
public:
    T *data;
    int ptr; //栈顶
    Stack(int len) : data(new T[len]), ptr(-1) {}
    ~Stack() { delete[] data; }
    void push(const T &d)
    {
        ++ptr;
        data[ptr] = d;
    }                               //进入栈顶
    T pop() { return data[ptr--]; } //退出栈顶
    T top() { return data[ptr]; }   //返回栈顶值
    bool isEmpty() { return ptr == -1; }
    int size() { return ptr + 1; }
};

const int maxn = 30;

char pre[maxn];
char post[maxn];

Stack<int> branch(30);

void branch_count(int pr1, int pr2, int po1, int po2)
{
    if (pr1 == pr2 && po1 == po2)
    {
        return;
    }
    else
    {
        int a, b, len, branchcnt = 0;
        a = pr1 + 1;
        b = po1;
        len = 0;
        while (b < po2)
        {
            while ((pre[a] != post[b + len]) && (b + len <= po2))
            {
                len++;
            }
            branchcnt++;                          //节点个数
            branch_count(a, a + len, b, b + len); //分离出一棵子树
            a = a + len + 1;
            b = b + len + 1;
            len = 0;
        }
        branch.push(branchcnt);
    }
}

int cal(int n, int m)
{
    int a = n - m + 1, ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans *= a++;
        ans /= i;
    }
    return ans;
}

int main()
{
    int m;
    scanf("%d", &m);
    scanf("%s %s", pre, post);
    int len = strlen(pre);
    branch_count(0, len - 1, 0, len - 1);
    int ans = 1;
    int len2 = branch.size(); //层数
    for (int i = 0; i < len2; i++)
    {
        ans *= cal(m, branch.data[i]);
    }
    printf("%d\n", ans);
    return 0;
}