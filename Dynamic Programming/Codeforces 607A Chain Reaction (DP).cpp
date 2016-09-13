#include <cstdio>
#include <cstring>
const int N = 1e6 + 1;
bool pos[N];
int pow[N], dp[N];
int n, ans;
int main()
{
	scanf("%d", &n);
	memset(pos, false, sizeof(pos));
	memset(pow, 0, sizeof(pow));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		pos[a] = true;
		pow[a] = b;
	}
	int ans = dp[0] = pos[0] ? 1 : 0;
	for (int i = 1; i < N; i++)
	{
		if (pos[i])
		{
			if (i - pow[i] - 1 < 0) dp[i] = 1;
			else dp[i] = dp[i - pow[i] - 1] + 1;
		}
		else dp[i] = dp[i - 1];
		if (dp[i] > ans) ans = dp[i];
	}
	printf("%d\n", n - ans);
	return 0;
}