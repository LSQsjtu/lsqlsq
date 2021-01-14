//最前方出去
#include <iostream>
class Stack
{
public:
    int *data;
    int ptr; //栈顶
    Stack(int len) : data(new int[len]), ptr(-1) {}
    ~Stack() { delete[] data; }
    void push(const int &d)
    {
        ++ptr;
        data[ptr] = d;
    }                                 //进入栈顶
    int pop() { return data[ptr--]; } //退出栈顶
    int top() { return data[ptr]; }   //返回栈顶值
};
using namespace std;
int main()
{
    int m, n, t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int a, j = 0;
        bool flag = 1;
        cin >> n >> m;
        Stack s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (flag)
            {
                if (j <= a)
                {
                    while (j < a)
                        s.push(j++);
                    j++;
                    if (s.ptr + 1 > m)
                        flag = 0;
                }
                else
                {
                    if (s.top() == a)//不满足最前方出去
                        s.pop();
                    else
                        flag = 0;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}