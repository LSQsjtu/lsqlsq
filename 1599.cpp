#include <iostream>
using namespace std;
class Stack
{
public:
    char *data;
    int ptr; //栈顶
    Stack(int len) : data(new char[len]), ptr(-1) {}
    ~Stack() { delete[] data; }
    void push(const char &d)
    {
        ++ptr;
        data[ptr] = d;
    } //进入栈顶
    char pop()
    {
        return data[ptr--];
    }                                //退出栈顶
    char top() { return data[ptr]; } //返回栈顶值
    bool empty() { return ptr == -1; }
};
int main()
{
    int n, a;
    char c;
    cin >> n;
    Stack s(n);
    Stack temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        switch (a)
        {
        case 1:
            cin >> c;
            temp.push(c);
            if (c == '(' || c == '[' || c == '{')
                s.push(c);
            else
            {
                if (s.empty())
                    s.push(c);
                else if ((c - s.top()) == 1 || (c - s.top()) == 2)
                    s.pop();
                else
                    s.push(c);
            }
            break;
        case 2:
            if (!temp.empty())
                switch (temp.top())
                {
                case ')':
                    if (s.empty() || s.top() != ')')
                        s.push('(');
                    else
                    {
                        s.pop();
                    }
                    temp.pop();
                    break;
                case ']':
                    if (s.empty() || s.top() != ']')
                        s.push('[');
                    else
                    {
                        s.pop();
                    }
                    temp.pop();
                    break;
                case '}':
                    if (s.empty() || s.top() != '}')
                        s.push('{');
                    else
                    {
                        s.pop();
                    }
                    temp.pop();
                    break;
                default:
                    s.pop();
                    temp.pop();
                    break;
                }
            break;
        case 3:
            cout << temp.top() << endl;
            break;
        case 4:
            if (s.empty())
                cout << "YES" << endl;
            else
            {
                cout << "NO" << endl;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}