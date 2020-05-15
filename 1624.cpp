#include <iostream>
using namespace std;

typedef long long ll;
struct set
{
	ll x;
	ll y;
	set(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
};

void quicksort(set *arr, int l, int r)
{
	if (l >= r)
		return;
	set tmp = arr[l];
	int i = l, j = r;
	do
	{
		while (i < j && arr[j].x <= tmp.x)
			--j;
		if (i < j)
			arr[i] = arr[j];
		while (i < j && arr[i].x >= tmp.x)
			++i;
		if (i < j)
			arr[j] = arr[i];
	} while (i < j);
	arr[i] = tmp;
	quicksort(arr, l, i - 1);
	quicksort(arr, i + 1, r);
}
template <class T>
class prior_queue
{
private:
	T *data;
	long long currentsize;
	
	void percolateDown(long long pos)
	{
		if (((pos << 1) + 1) >= currentsize)
			return;
		long long change = (pos << 1) + 1;
		if (((change + 1) < currentsize) && data[change + 1] < data[change])
			++change;
		if (data[pos] > data[change])
		{
			T x = data[pos];
			data[pos] = data[change];
			data[change] = x;
			percolateDown(change);
		}
	}

public:
	prior_queue()
	{
		currentsize = 0;
		data = new T[300000];
	}
	
	~prior_queue() { delete[] data; }
	T pop()
	{
		T x = data[0];
		data[0] = data[--currentsize];
		percolateDown(0);
		return x;
	}
	void push(const T &a)
	{
		++currentsize;
		long long hole = currentsize - 1;
		while (hole > 0 && data[((hole - 1) >> 1)] > a)
		{
			data[hole] = data[((hole - 1) >> 1)];
			--hole;
			hole >>= 1;
		}
		data[hole] = a;
	}
	T top() { return data[0]; }
	long long size() { return currentsize; }
};
prior_queue<ll> prior;

ll n, M, x, y, now = 0;
set me, *student;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> me.x >> me.y;
	student = new set[n];
	for (ll i = 0; i < n - 1; ++i)
	{
		cin >> x >> y;
		if (x > me.x)
			prior.push(y - x + 1);
		else
		{
			student[now].x = x;
			student[now].y = y;
			++now;
		}
	}
	ll rank = prior.size(), find = 0;
	quicksort(student, 0, now - 1);
	while (prior.size() > 0 && me.x >= prior.top() && find < now)
	{
		me.x -= prior.pop();
		while (find < now && student[find].x > me.x)
		{
			prior.push(student[find].y - student[find].x + 1);
			++find;
		}
		if (prior.size() < rank)
			rank = prior.size();
	}
	cout << rank + 1;
	return 0;
}