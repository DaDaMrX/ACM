/*
POJ 2823 Sliding Window (单调队列)
PS：STL deque， G++ TLE，C++ AC
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, k;
int a[N];
deque<int> dq;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	dq.clear();
	for (int i = 1; i < k; i++)
	{
		while (!dq.empty() && a[i] < a[dq.back()]) dq.pop_back();
		dq.push_back(i);
	}
	for (int i = k; i <= n; i++)
	{
		while (!dq.empty() && a[i] < a[dq.back()]) dq.pop_back();
		dq.push_back(i);
		while (!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();

		if (i < n) printf("%d ", a[dq.front()]);
		else printf("%d\n", a[dq.front()]);
	}

	dq.clear();
	for (int i = 1; i < k; i++)
	{
		while (!dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
		dq.push_back(i);
	}
	for (int i = k; i <= n; i++)
	{
		while (!dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
		dq.push_back(i);
		while (!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();

		if (i < n) printf("%d ", a[dq.front()]);
		else printf("%d\n", a[dq.front()]);
	}
	return 0;
}