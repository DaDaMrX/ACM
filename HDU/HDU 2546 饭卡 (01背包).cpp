#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
int n, m;
int c[N], dp[N];
int main()
{
	while (scanf("%d", &n), n)
	{
		int maxc = -1, maxi;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &c[i]);
			if (c[i] > maxc) maxc = c[maxi = i];
		}
		scanf("%d", &m);
		if (m < 5)
		{
			printf("%d\n", m);
			continue;
		}
		m -= 5;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			if (i == maxi) continue;
			for (int j = m; j >= c[i]; j--)
				dp[j] = max(dp[j], dp[j - c[i]] + c[i]);
		}
		printf("%d\n", m + 5 - dp[m] - maxc);
	}
	return 0;
}