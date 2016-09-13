/*
UVa 116 Unidirectional TSP (DP+字典序最小路径)
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x7f7f7f7f
#define M 110
#define N 110

int dp[M][N], path[M][N];
int m, n;

int min3(int a, int b, int c, int j)
{
	int i = a;
	if (dp[b][j] < dp[i][j]) i = b;
	if (dp[c][j] < dp[i][j]) i = c;
	return i;
}

int main()
{
	while (~scanf("%d%d", &m, &n))
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &dp[i][j]);

		for (int j = n - 2; j >= 0; j--)
		{
			for (int i = 0; i < m; i++)
			{
				int minx = INF;
				path[i][j] = INF;

				int t = (i - 1 + m) % m;
				if (dp[t][j + 1] < minx)
				{
					minx = dp[t][j + 1];
					path[i][j] = t;
				}
				else if (dp[t][j + 1] == minx)
				{
					path[i][j] = min(path[i][j], t);
				}

				t = i;
				if (dp[t][j + 1] < minx)
				{
					minx = dp[t][j + 1];
					path[i][j] = t;
				}
				else if (dp[t][j + 1] == minx)
				{
					path[i][j] = min(path[i][j], t);
				}

				t = (i + 1) % m;
				if (dp[t][j + 1] < minx)
				{
					minx = dp[t][j + 1];
					path[i][j] = t;
				}
				else if (dp[t][j + 1] == minx)
				{
					path[i][j] = min(path[i][j], t);
				}

				dp[i][j] += minx;
			}
		}

		int mini = -1;
		for (int i = 0; i < m; i++)
			if (mini == -1 || dp[i][0] < dp[mini][0]) mini = i;

		printf("%d", mini + 1);
		int i = mini;
		for (int j = 0; j < n - 1; j++)
		{
			printf(" %d", path[i][j] + 1);
			i = path[i][j];
		}
		printf("\n");
		printf("%d\n", dp[mini][0]);
	}
}