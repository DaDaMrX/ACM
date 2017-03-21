#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

int n, a[N];
ll dp[N][2];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	dp[1][0] = dp[1][1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i - 1])
		{
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i] - a[i - 1]);
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		}
		else
		{
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + a[i - 1] - a[i]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	printf("%lld\n", max(dp[n][0], dp[n][1]));
	return 0;
}
