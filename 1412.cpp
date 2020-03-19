#include <iostream>
using namespace std;
void tervese(int a[], int len)
{
    for (int i = 0; i < len / 2; ++i)
    {
        int temp = a[i];
        a[i] = a[len - i];
        a[len - i] = temp;
    }
}
int main()
{
    int a[500] = {0}, b[500] = {0}, i = 0, lena, lenb;
    char c;
    while ((c = cin.get()) != '\n')
        a[i++] = c - '0';
    lena = i;
    tervese(a, lena);
    i = 0;
    while ((c = cin.get()) != '\n')
        b[i++] = c - '0';
    lenb = i;
    tervese(b, lenb);
}