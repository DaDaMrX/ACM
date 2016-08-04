/*
HDU 3530 Subsequence (单调队列)
两个单调队列， 一个维护最大值，一个维护最小值
PS：从队头出队给now，i-now为长度？
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, m, k;
int a[N];
deque<int> dq1, dq2;

int main()
{
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dq1.clear(); dq2.clear();
		int now = 0, ans = 0;
		for (int i = 1; i <= n; i++)
		{
			while (!dq1.empty() && a[i] < a[dq1.back()]) dq1.pop_back();
			dq1.push_back(i);
			while (!dq2.empty() && a[i] > a[dq2.back()]) dq2.pop_back();
			dq2.push_back(i);
			while (!dq1.empty() && !dq2.empty() && a[dq2.front()] - a[dq1.front()] > k)
			{
				if (dq1.front() < dq2.front())
				{
					now = dq1.front();
					dq1.pop_front();
				}
				else
				{
					now = dq2.front();
					dq2.pop_front();
				}
			}
			if (!dq1.empty() && !dq2.empty() && a[dq2.front()] - a[dq1.front()] >= m)
				ans = max(ans, i - now);
		}
		printf("%d\n", ans);
	}
	return 0;
}