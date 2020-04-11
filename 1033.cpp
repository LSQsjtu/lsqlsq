#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
long long zhongnum = 0, houzhuinum = 0, myStacknum = 0;

void transfrom(char *input, long long *output, bool *cate)
{
    int j = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        j++;
        if (input[i] == '-' && (i == 0 || (input[i - 1] != '+' && input[i - 1] != '-' && input[i - 1] != '*' && input[i - 1] != '/' && input[i - 1] != '^' && input[i - 1] != '(')))
        {
            output[++zhongnum] = 21;
            cate[j] = true;
        }
        else if (input[i] == '+')
        {
            output[++zhongnum] = 20;
            cate[j] = true;
        }
        else if (input[i] == '*')
        {
            output[++zhongnum] = 10;
            cate[j] = true;
        }
        else if (input[i] == '/')
        {
            output[++zhongnum] = 11;
            cate[j] = true;
        }
        else if (input[i] == '^')
        {
            output[++zhongnum] = 1;
            cate[j] = true;
        }
        else if (input[i] == '(')
        {
            output[++zhongnum] = 0;
            cate[j] = true;
        }
        else if (input[i] == ')')
        {
            output[++zhongnum] = 100;
            cate[j] = true;
        }
        else //数
        {
            char temp[100] = "";
            for (int t = 0;; i++, t++)
            {
                temp[t] = input[i];
                temp[t + 1] = '\0';
                if (!((input[i + 1] >= '0' && input[i + 1] <= '9') || input[i + 1] == '.'))
                {
                    break;
                }
            }
            double getInt;
            sscanf(temp, "%lf", &getInt);
            output[++zhongnum] = getInt;
            cate[j] = false;
        }
    }

    //为^添加括号
    for (int i = zhongnum; i >= 1; i--)
    {
        if (output[i] == '^' && cate[i])
        {
            int kl = 0, kr = 0;
            for (int j = i - 1; j >= 1; j--)
            {
                if (output[j] == '(' && cate[j])
                    kl++;
                else if (output[j] == ')' && cate[j])
                    kr++;
                if (kl == kr)
                {
                    i++;
                    for (int n = zhongnum; n >= j; n--)
                    {
                        output[n + 1] = output[n];
                        cate[n + 1] = cate[n];
                    }
                    zhongnum++;
                    output[j] = 0;
                    cate[j] = true;
                    break;
                }
            }
            kl = 0, kr = 0;
            for (int j = i + 1; j <= zhongnum; j++)
            {
                if (output[j] == 0 && cate[j])
                    kl++;
                else if (output[j] == 100 && cate[j])
                    kr++;
                if (kl == kr)
                {
                    j++;
                    for (int n = zhongnum - 1; n >= j; n--)
                    {
                        output[n + 1] = output[n];
                        cate[n + 1] = cate[n];
                    }
                    zhongnum++;
                    output[j] = 100;
                    cate[j] = true;
                    break;
                }
            }
        }
    }
}
bool calHou(long long *houzhui, bool *cateHouzhui, long long &ans)
{
    bool isExist[100];
    for (int i = 1; i <= houzhuinum; i++)
        isExist[i] = true;

    for (int i = 1; i <= houzhuinum; i++)
    {
        if (!isExist[i])
            continue;
        if (cateHouzhui[i] == true)
        {
            //分类
            if (houzhui[i] == 1)
            {
                //不存在
                isExist[i] = false;
                long long a, b;
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        b = houzhui[i];
                        isExist[i] = false;
                        break;
                    }
                }
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        a = houzhui[i];
                        break;
                    }
                }
                if (a == 0 && b < 0)
                    return -1;
                houzhui[i] = pow(double(a), double(b));
            }
            else if (houzhui[i] == 10)
            {
                //不存在
                isExist[i] = false;
                long long a, b;
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        b = houzhui[i];
                        isExist[i] = false;
                        break;
                    }
                }
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        a = houzhui[i];
                        break;
                    }
                }
                houzhui[i] = a * b;
            }
            else if (houzhui[i] == 11)
            {
                //不存在
                isExist[i] = false;
                long long a, b;
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        b = houzhui[i];
                        isExist[i] = false;
                        break;
                    }
                }
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        a = houzhui[i];
                        break;
                    }
                }
                if (b == 0)
                    return 0;
                houzhui[i] = a / b;
            }
            else if (houzhui[i] == 20)
            {
                //不存在
                isExist[i] = false;
                long long a, b;
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        b = houzhui[i];
                        isExist[i] = false;
                        break;
                    }
                }
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        a = houzhui[i];
                        break;
                    }
                }
                houzhui[i] = a + b;
            }
            else if (houzhui[i] == 21)
            {
                //不存在
                isExist[i] = false;
                long long a, b;
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        b = houzhui[i];
                        isExist[i] = false;
                        break;
                    }
                }
                for (;; i--)
                {
                    if (isExist[i])
                    {
                        a = houzhui[i];
                        break;
                    }
                }
                houzhui[i] = a - b;
            }
        }
    }
    ans = houzhui[1];
    return 1;
}
bool cal(char *input, long long &ans)
{
    int kl = 0, kr = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '(')
            kl++;
        else if (input[i] == ')')
            kr++;
        if (kr > kl)
            return 0;
    }
    if (kl != kr)
        return 0;

    long long zhongzhui[100];

    long long houzhui[100];

    bool houzhuiCate[100];
    bool zhongzhuiCate[100];

    transfrom(input, zhongzhui, zhongzhuiCate);

    //栈表达式,转为后缀表达式
    int myStack[100];

    for (int i = 1; i <= zhongnum; i++)
    {
        //操作数
        if (zhongzhuiCate[i] == false)
        {
            //塞入
            houzhui[++houzhuinum] = zhongzhui[i];
            houzhuiCate[houzhuinum] = false;
        }
        else
        {
            //符号
            if (zhongzhui[i] == 0)
            {
                //入栈
                myStack[++myStacknum] = 0;
            }
            else if (zhongzhui[i] == 100)
            {
                //出栈
                long long tempStack[100];
                tempStack[0] = 0;
                for (int j = myStacknum; j > 0; j--)
                {
                    if (myStack[j] == 0)
                    {
                        myStacknum--;
                        break;
                    }
                    tempStack[++tempStack[0]] = myStack[j];
                    myStacknum--;
                }
                //塞入
                for (int j = 1; j <= tempStack[0]; j++)
                {
                    houzhui[++houzhuinum] = tempStack[j];
                    houzhuiCate[houzhuinum] = true;
                }
            }
            else
            {
                long long temp[100];
                temp[0] = 0;
                for (; (zhongzhui[i] - myStack[myStacknum] > -5) && myStack[myStacknum] != 0;)
                {
                    temp[++temp[0]] = myStack[myStacknum--];
                }

                myStack[++myStacknum] = zhongzhui[i];

                for (; temp[0] > 0;)
                {
                    houzhui[++houzhuinum] = temp[temp[0]--];
                    houzhuiCate[houzhuinum] = true;
                }
            }
        }
    }

    for (int i = myStacknum; i > 0; i--)
    {
        houzhui[++houzhuinum] = myStack[i];
        houzhuiCate[houzhuinum] = true;
    }

    if (calHou(houzhui, houzhuiCate, ans))
        return 1;
    else
        return 0;
}

int main()
{
    char input[100] = "";
    char temp[100];
    while (cin >> temp)
    {
        if (temp[0] == '-' && temp[1] >= 48 && temp[1] <= 57)
        {
            char temp1[100];
            sprintf(temp1, "(%s)", temp);
            strcat(input, temp1);
        }
        else
            strcat(input, temp);
        if (getchar() == '\n')
            break;
    }

    char expr[101];
    int j = 0;

    if (input[0] == '-')
    {
        expr[0] = '0';
        ++j;
    }

    for (int i = 0; i < 100; i++)
    {
        if (input[i] != ' ')
        {
            expr[j] = input[i];
            j++;
        }
    }

    long long value;

    if (cal(expr, value))
        cout << value;
    else
        cout << "Error";

    return 0;
}