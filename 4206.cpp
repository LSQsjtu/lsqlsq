#include <iostream>
#include <cstdio>
using namespace std;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int n, m;
int a[1001][1001] = {0};
int f(int x, int y)
{
    if (x <= n && y <= m)
        return a[x][y];
    else if (x <= n)
        return a[x][m];
    else if (y <= m)
        return a[n][y];
    else
        return a[n][m];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int temp;
            scanf("%1d", &temp);
            a[i][j] = temp + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];//表示i，j矩形内有多少个1
        }
    }

    //k一定为质数
    int max = n > m ? n : m;

    int num = 1000000001;
    for (int i = 0; prime[i] < max; ++i)
    {
        int k = prime[i];
        int tempnum = 0;
        for (int i = 1; i <= n; i += k)
        {
            for (int j = 1; j <= m; j += k)
            {
                int posx = i + k - 1, posy = j + k - 1;
                int temp = f(posx, posy) - f(posx - k, posy) - f(posx, posy - k) + f(posx - k, posy - k);
                tempnum += temp < k * k - temp ? temp : k * k - temp;
            }
        }
        if (tempnum < num)
            num = tempnum;
    }

    printf("%d", num);

    return 0;
}