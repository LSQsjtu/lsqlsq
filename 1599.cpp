#include <iostream>
using namespace std;
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
    } //进入栈顶
    T pop()
    {
        return data[ptr--];
    }                             //退出栈顶
    T top() { return data[ptr]; } //返回栈顶值
    bool isEmpty() { return ptr == -1; }
};
int main()
{
    int n, a;
    char c;
    cin >> n;
    Stack<char> s(n);
    Stack<char> temp(n);
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
                if (s.isEmpty())
                    s.push(c);
                else if ((c - s.top()) == 1 || (c - s.top()) == 2)
                    s.pop();
                else
                    s.push(c);
            }
            break;
        case 2:
            if (!temp.isEmpty())
                switch (temp.top())
                {
                case ')':
                    if (s.isEmpty() || s.top() != ')')
                        s.push('(');
                    else
                    {
                        s.pop();
                    }
                    temp.pop();
                    break;
                case ']':
                    if (s.isEmpty() || s.top() != ']')
                        s.push('[');
                    else
                    {
                        s.pop();
                    }
                    temp.pop();
                    break;
                case '}':
                    if (s.isEmpty() || s.top() != '}')
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
            if (s.isEmpty())
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