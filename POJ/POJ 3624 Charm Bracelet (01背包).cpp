#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 3500
#define M 13000
int w[N], d[N];
int dp[M];
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &w[i], &d[i]);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], d[i] + dp[j - w[i]]);
		}
	printf("%d\n", dp[m]);
	return 0;
}