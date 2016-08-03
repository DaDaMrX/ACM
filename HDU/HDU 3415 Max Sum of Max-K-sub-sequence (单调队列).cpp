/*
HDU 3415 Max Sum of Max-K-sub-sequence (单调队列)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, k;
int a[2 * N], sum[2 * N];
deque<int> dq;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i + n] = a[i];
		}
		sum[0] = 0;
		for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];

		dq.clear();
		int ans = -INF, left, right;
		for (int i = 1; i <= 2 * n; i++)
		{
			while (!dq.empty() && sum[i - 1] < sum[dq.back()]) dq.pop_back();
			dq.push_back(i - 1);
			while (!dq.empty() && i - dq.front() > k) dq.pop_front();

			int total = sum[i] - sum[dq.front()];
			if (total > ans)
			{
				ans = total;
				left = dq.front() + 1;
				right = i;
			}
		}

		if (left > n) left -= n;
		if (right > n) right -= n;
		printf("%d %d %d\n", ans, left, right);
	}
	return 0;
}