#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 210;

struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;

int n, m;
int val[N], dp[N][N];

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

void dfs(int u, int m)
{
	dp[u][1] = val[u];
	if (m <= 1) return;
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		dfs(v, m - 1);
		for (int j = m; j > 1; j--)
			for (int k = 1; k < j; k++)
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
	}
}

int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		memset(head, -1, sizeof(head));
		num = 0;
		for (int i = 1; i <= n; i++)
		{
			int from, w;
			scanf("%d%d", &from, &w);
			add(from, i);
			val[i] = w;
		}
		val[0] = 0;

		memset(dp, 0, sizeof(dp));
		dfs(0, m + 1);
		printf("%d\n", dp[0][m + 1]);
	}
	return 0;
}