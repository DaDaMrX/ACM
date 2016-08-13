#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 11;

int n, m;
int three[N], f[60000][N];
int map[N][N];
int dp[60000][N];

void init()
{
	three[0] = 1;
	for (int i = 1; i < N; i++) three[i] = three[i - 1] * 3;
	for (int S = 0; S < three[N - 1]; S++)
	{
		int sum = S;
		for (int i = 0; i < N && sum; i++)
		{
			f[S][i] = sum % 3;
			sum /= 3;
		}
	}
}

int main()
{
	init();
	while (~scanf("%d%d", &n, &m))
	{
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= m; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			a--; b--;
			if (w < map[a][b]) map[a][b] = map[b][a] = w;
		}

		int sum = three[n];
		for (int S = 1; S < sum; S++)
			for (int i = 0; i < n; i++)
			{
				if (!f[S][i]) continue;
				if (S == three[i])
				{
					dp[S][i] = 0;
					continue;
				}
				dp[S][i] = INF;
				for (int j = 0; j < n; j++)
				{
					if (!f[S][j] || j == i) continue;
					if (map[j][i] < INF)
						dp[S][i] = min(dp[S][i], dp[S - three[i]][j] + map[j][i]);
				}
			}

		int left = 0;
		for (int i = 0; i < n; i++) left += three[i];
		int ans = INF;
		for (int S = left; S < sum; S++)
			for (int i = 0; i < n; i++)
			{
				int j;
				for (j = 0; j < n; j++)
					if (!f[S][j]) break;
				if (j < n) break;
				ans = min(ans, dp[S][i]);
			}
		if (ans < INF) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}