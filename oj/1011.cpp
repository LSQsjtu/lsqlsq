#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
private:
  double x, y;

public:
  MyComplex operator+(const MyComplex &c)
  {
    MyComplex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
  }
  MyComplex operator+=(const MyComplex &c)
  {
    x = x + c.x;
    y = y + c.y;
    return *this;
  }
  MyComplex operator-(const MyComplex &c)
  {
    MyComplex temp;
    temp.x = x - c.x;
    temp.y = y - c.y;
    return temp;
  }
  MyComplex operator-=(const MyComplex &c)
  {
    x = x - c.x;
    y = y - c.y;
    return *this;
  }
  MyComplex operator*(const MyComplex &c)
  {
    MyComplex temp1;
    temp1.x = (x * c.x) - (y * c.y);
    temp1.y = (x * c.y) + (y * c.x);
    return temp1;
  }
  MyComplex operator*=(const MyComplex &c)
  {
    double z = x;
    x = (x * c.x) - (y * c.y);
    y = (z * c.y) + (y * c.x);
    return *this;
  }
  MyComplex operator/(const MyComplex &c)
  {
    MyComplex temp;
    double temp1 = c.x * c.x + c.y * c.y;
    temp.x = ((x * c.x) + (y * c.y)) / temp1;
    temp.y = ((y * c.x) - (x * c.y)) / temp1;
    return temp;
  }
  MyComplex operator/=(const MyComplex &c)
  {
    double z = x;
    double temp1 = c.x * c.x + c.y * c.y;
    x = ((x * c.x) + (y * c.y)) / temp1;
    y = ((y * c.x) - (z * c.y)) / temp1;
    return *this;
  }
  friend ostream &operator<<(ostream &os, MyComplex c)
  {
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << c.x << ' ' << c.y;
    return os;
  }
  friend istream &operator>>(istream &is, MyComplex &c)
  {
    is >> c.x >> c.y;
    return is;
  }
};

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;

  cout << z1 + z2 << endl;
  cout << z1 - z2 << endl;
  cout << z1 * z2 << endl;
  cout << z1 / z2 << endl;
  cout << (z1 += z2) << endl;
  cout << (z1 -= z2) << endl;
  cout << (z1 *= z2) << endl;
  cout << (z1 /= z2) << endl;

  return 0;
}