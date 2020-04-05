#include<iostream>
using namespace std;
int main()
{
    int n,q,k,*a;
    cin>>n;
    a=new int [n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin >>q;
    for (int i = 0; i < q; i++)
    {
        cin>>k;
    }
    
    delete []a;
    return 0;
}