#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 510
#define M 10010
#define INF 100000000
int w[N], p[N], dp[M];
int n, m;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int e, f;
		scanf("%d%d", &e, &f);
		m = f - e;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &w[i]);
		dp[0] = 0;
		for (int i = 1; i <= m; i++) dp[i] = INF;
		for (int i = 1; i <= n; i++)
			for (int j = w[i]; j <= m; j++)
				dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
		if (dp[m] == INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
	}
	return 0;
}