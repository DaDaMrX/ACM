#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 110
#define M 100010
int h[N], k[N], dp[M];
int n, m;
int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) scanf("%d%d", &h[i], &k[i]);
		scanf("%d", &m);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = k[i]; j <= m; j++)
				dp[j] = max(dp[j], dp[j - k[i]] + h[i]);
		printf("%d\n", dp[m]);
	}
	return 0;
}