#include <iostream>
using namespace std;

long long n;
const long long x = 1000000007;
class matrix
{
public:
    long long a11, a12, a21, a22;
    matrix(long long a = 0, long long  b = 0, long long c = 0, long long d = 0) : a11(a), a12(b), a21(c), a22(d) {}
};

matrix operator*(matrix &m1, matrix &m2)
{
    matrix tmp;
    tmp.a11 = (m1.a11 * m2.a11 + m1.a12 * m2.a21) % x;
    tmp.a12 = (m1.a11 * m2.a12 + m1.a12 * m2.a22) % x;
    tmp.a21 = (m1.a21 * m2.a11 + m1.a22 * m2.a21) % x;
    tmp.a22 = (m1.a21 * m2.a12 + m1.a22 * m2.a22) % x;
    return tmp;
}
int main()
{
    cin >> n;
    ++n;
    matrix f(1, 1, 1, 0),an(1,0,0,1);
    while (n)
    {
        if (n & 1) //奇数
            an = an * f;//二进制有没有这一位
        f = f * f;
        n >>= 1;
    }
    cout << an.a21 << endl;
    return 0;
}
/*
a^b mod c=((a²)^(b/2)) mod c , b是偶数
a^b mod c=((a²)(b/2)*a) mod c ,b是奇数
1.如果b是偶数,我们可以记k=a²modc,那么(k)^(b/2)mod c 就可以了.
2.如果b是奇数,我们也可以记k=a²modc,那么((k)^(b/2)mod c就可以了*/
long long int pow(int a,int n)//求a的n次幂
{
    if (n==0)
        return 1;
    if (n==1)
        return a;
    long long int ans=pow(a,n/2);//从函数的功能区理解递归
    ans*=ans;
    if (n%2==1)
        ans*=a;
    return ans;
}
//二分法