/********************************************************************************
Problem M. Jumping along the Hummocks (DP)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

int n, a[N], b[N], c[N], dp[N];

int main()
{
	scanf("%d", &n);
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		b[i] = c[a[i]];
		c[a[i]] = i;
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (b[i]) dp[i] = min(dp[i - 1], dp[b[i]]) + 1;
		else dp[i] = dp[i - 1] + 1;
	}
	printf("%d\n", dp[n]);
	return 0;
}
