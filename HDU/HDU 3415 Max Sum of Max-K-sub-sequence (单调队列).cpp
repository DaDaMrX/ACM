/*
HDU 3415 Max Sum of Max-K-sub-sequence (单调队列)
循环序列，将序列复制一份加到原序列之后
求和问题，预处理前缀和数组，求和转化为做减法
要求以i为结尾向前不超过k个元素中的最大和，只需求前k个元素中最小的sum[]
单调队列，要求以1~2n结尾的最大和，要依次入队0~2n-1，故循环到i，入队i-1
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
int sum[2 * N];
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
			scanf("%d", &sum[i]);
			sum[i + n] = sum[i];
		}
		sum[0] = 0;
		for (int i = 2; i <= 2 * n; i++) sum[i] += sum[i - 1];

		int ans = -INF, left, right;
		dq.clear();
		for (int i = 1; i <= 2 * n; i++)
		{
			while (!dq.empty() && sum[i - 1] < sum[dq.back()]) dq.pop_back();
			dq.push_back(i - 1);
			while (!dq.empty() && i - dq.front() > k) dq.pop_front();

			int total = sum[i] - sum[dq.front()];
			if (total < ans) continue;
			if (total > ans)
			{
				ans = total;
				left = dq.front() + 1;
				right = i;
				continue;
			}
			if (dq.front() + 1 > left) continue;
			if (dq.front() + 1 < left)
			{
				left = dq.front() + 1;
				right = i;
				continue;
			}
			if (i < right) right = i;
		}

		if (left > n) left -= n;
		if (right > n) right -= n;
		printf("%d %d %d\n", ans, left, right);
	}
	return 0;
}