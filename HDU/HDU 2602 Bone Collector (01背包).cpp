#include <cstdio>
#include <cstring>
#define N 1010
int v[N], w[N];
int dp[N][N];
int n, m;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++)
			{
				if (j >= v[i] && w[i] + dp[i - 1][j - v[i]] > dp[i - 1][j])
					dp[i][j] = w[i] + dp[i - 1][j - v[i]];
				else dp[i][j] = dp[i - 1][j];
			}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}