/*
HDU 4193 Non-negative Partial Sums (单调队列)
循环序列，将序列复制一份接到后面
可以选择将前0~n-1个元素移到后面，共能产生n种序列
与序列和有关，预处理出前缀和数组sum[]
第i项到第j项和就转化为一步减法sum[j] - sum[i - 1]
对某一序列a[i]~a[i+n-1]，前i项和都要小于等于0，只需min{ a[i]~a[i+n-1] } - sum[i - 1] >= 0
N=1e6，因此需要O(n)地得到每一个长度为n的序列中的最小值，故利用单调队列
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, sum[2 * N];
deque<int> dq;

int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &sum[i]);
			sum[i + n] = sum[i];
		}
		sum[0] = 0;
		for (int i = 2; i < 2 * n; i++) sum[i] += sum[i - 1];

		dq.clear();
		for (int i = 1; i < n; i++)
		{
			while (!dq.empty() && sum[i] <= sum[dq.back()]) dq.pop_back();
			dq.push_back(i);
		}
		int ans = 0;
		for (int i = n; i < 2 * n; i++)
		{
			while (!dq.empty() && sum[i] <= sum[dq.back()]) dq.pop_back();
			dq.push_back(i);
			if (!dq.empty() && i - dq.front() + 1 > n) dq.pop_front();
			if (sum[dq.front()] - sum[i - n] >= 0) ans++;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}