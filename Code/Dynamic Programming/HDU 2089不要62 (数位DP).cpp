#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 10;

int dp[N][10];

void init()
{
	memset(dp, 0, sizeof(dp));
	for (int j = 0; j <= 9; j++) dp[0][j] = 1;
	dp[0][4] = 0;
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 4) continue;
			for (int k = 0; k <= 9; k++)
			{
				if (j == 6 && k == 2) continue;
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}

ll calc(int n)
{
	int a[N], len = 0;
	while (n) a[len++] = n % 10, n /= 10;
	a[len] = 0;
	ll ans = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = 0; j < a[i]; j++)
		{
			if (j == 4) continue;
			if (a[i + 1] == 6 && j == 2) continue;
			ans += dp[i][j];
		}
		if (a[i] == 4 || (a[i + 1] == 6 && a[i] == 2)) break;
	}
	return ans;
}

int main()
{
	init();
	int n, m;
	while (scanf("%d%d", &n, &m), n || m)
		printf("%lld\n", calc(m + 1) - calc(n));
	return 0;
}
