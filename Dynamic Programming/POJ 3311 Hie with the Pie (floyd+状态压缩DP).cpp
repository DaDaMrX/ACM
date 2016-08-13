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

		for (int S = 0; S < (1 << n); S++)
			for (int i = 0; i < n; i++)
			{
				if (!(S & (1 << i))) continue;
				if (S == (1 << i))
				{
					dp[S][i] = map[0][i];
					continue;
				}
				dp[S][i] = INF;
				for (int j = 0; j < n; j++)
					if (S & (1 << j) && j != i)
						dp[S][i] = min(dp[S][i], dp[S & ~(1 << i)][j] + map[j][i]);
			}

		printf("%d\n", dp[(1 << n) - 1][0]);
	}
	return 0;
}