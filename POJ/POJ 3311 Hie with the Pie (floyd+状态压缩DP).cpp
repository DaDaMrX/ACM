#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 15;
int map[N][N];
int n;
int dp[1 << N][N];

void floyd()
{
	for (int i = 0; i < n; i++) map[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int main()
{
	while (scanf("%d", &n), n)
	{
		n++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		floyd();

		memset(dp, 0x3f, sizeof(dp));
		dp[(1 << n) - 1][0] = 0;

		for (int S = (1 << n) - 2; S >= 0; S--)
			for (int v = 0; v < n; v++)
				for (int u = 0; u < n; u++)
					if (!(S >> u & 1) && dp[S | 1 << u][u] < INF)
						dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + map[v][u]);

		printf("%d\n", dp[0][0]);
	}
	return 0;
}