#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 27;

int main()
{
	int n, id, ans;
	char str[60];

	while (cin >> n && n)
	{
		bool vis[MAX] = {0}, tan[MAX] = {0}; //vis代表客人的来和去。tan代表客房是否被利用。
		cin >> str;
		ans = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			id = str[i] - 'A';
			if (!vis[id])
			{
				vis[id] = true;
				if (n > 0)
				{
					n--;
					tan[id] = true;
				}
				else
					ans++;
			}
			else
			{
				if (tan[id])
					n++;
			}
		}
		if (ans == 0)
			printf("All customers tanned successfully.\n");
		else
			printf("%d customer(s) walked away.\n", ans);
	}
	return 0;
}