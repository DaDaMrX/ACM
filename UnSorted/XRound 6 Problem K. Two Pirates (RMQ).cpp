/********************************************************************************
XRound 6 Problem K. Two Pirates (RMQ)
相等情况如何处理
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, a[N];
bool flag[N];

int dp[N][20], lg[N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = ((i & (i - 1))) == 0 ? lg[i - 1] + 1 : lg[i - 1];
		dp[i][0] = i;
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			int x = dp[i][j - 1], y = dp[i + (1 << (j - 1))][j - 1];
			dp[i][j] = a[x] >= a[y] ? x : y;
		}
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	int x = dp[left][k], y = dp[right - (1 << k) + 1][k];
	return a[x] >= a[y] ? x : y;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	ST(n);
	memset(flag, false, sizeof(flag));
	ll ans = 0, ans2 = 0;
	int i = 1;
	while (true)
	{
		int j;
		for (j = i + 1; j <= n; j++)
			if (!flag[j]) break;
		if (a[i] >= a[j])
		{
			ans += a[i];
			ans2 += a[j];
			for (i += 2; i <= n; i++)
				if (!flag[i]) break;
		}
		else
		{
			ans2 += a[i];
			int t = rmq(j, n);
			ans += a[t];
			flag[t] = true;
			for (i++; i <= n; i++)
				if (!flag[i]) break;
		}
		if (i > n) break;
	}
	printf("%I64d %I64d\n", ans, ans2);
	return 0;
}
