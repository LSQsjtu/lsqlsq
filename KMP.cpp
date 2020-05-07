#include <iostream>
#include <cstring>
using namespace std;
char A[10000005], B[1000005];
int Next[1000005];//回溯指针

int kmp(char *A, char *B, int Next[])
{
    int lenA, lenB;
    lenA = strlen(A);
    lenB = strlen(B);

    for (int i = 0, j = 0; i < lenA; i++)
    {
        while (j > 0 && B[j] != A[i])
        {
            j = Next[j - 1];//失配
        }
        if (B[j] == A[i])
        {
            j++;
        }
        if (j == lenB)
        {
            return i - lenB + 1;
        }
    }
    return lenA;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;

    int lenB = strlen(B);
    Next[0] = 0;

    for (int i = 1, j = 0; i < lenB; i++)
    {
        while (j > 0 && B[i] != B[j])
        {
            j = Next[j - 1];//取前缀的最长公共前后缀
        }
        if (B[i] == B[j])
        {
            j++;//相比于i-1多一位公共前后缀
        }
        Next[i] = j;
    }

    cout << kmp(A, B, Next);

    return 0;
}