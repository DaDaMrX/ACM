/*
UVa 116 Unidirectional TSP (DP+字典序最小路径)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;
const int M = 15;

int dp[M][N], pre[M][N];
int n, m;

void printPath(int i, int j)
{
	if (j == 1)
	{
		printf("%d", i);
		return;
	}
	printPath(pre[i][j], j - 1);
	printf(" %d", i);
}

int main()
{
	while (~scanf("%d%d", &m, &n))
	{
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &dp[i][j]);

		for (int j = 2; j <= n; j++)
		{
			int minx = dp[1][j - 1]; pre[1][j] = 1;
			if (dp[2][j - 1] < minx)
			{
				minx = dp[2][j - 1];
				pre[1][j] = 2;
			}
			if (dp[m][j - 1] < minx)
			{
				minx = dp[m][j - 1];
				pre[1][j] = m;
			}
			dp[1][j] += minx;

			for (int i = 2; i < m; i++)
			{
				minx = dp[i - 1][j - 1]; pre[i][j] = i - 1;
				if (dp[i][j - 1] < minx)
				{
					minx = dp[i][j - 1];
					pre[i][j] = i;
				}
				if (dp[i + 1][j - 1] < minx)
				{
					minx = dp[i + 1][j - 1];
					pre[i][j] = i + 1;
				}
				dp[i][j] += minx;				
			}

			minx = dp[1][j - 1]; pre[m][j] = 1;
			if (dp[m - 1][j - 1] < minx)
			{
				minx = dp[m - 1][j - 1];
				pre[m][j] = m - 1;
			}
			if (dp[m][j - 1] < minx)
			{
				minx = dp[m][j - 1];
				pre[m][j] = m;
			}
			dp[m][j] += minx;
		}

		int x = 1;
		for (int i = 2; i <= m; i++) 
			if (dp[i][n] < dp[x][n]) x = i;
		printPath(x, n); printf("\n");
		printf("%d\n", dp[x][n]);
	}
	return 0;
}