#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 110;
const int M = 210;

struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;
bool vis[N];
int n, m;

int dp[N][M][2], val[N];

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

void dfs(int u)
{
	vis[u] = true;
	for (int j = 0; j <= m; j++) dp[u][j][0] = dp[u][j][1] = val[u];
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if (vis[v]) continue;
		dfs(v);
		for (int j = m; j > 0; j--)
			for (int k = 0; k < j; k++)
			{
				if (j - k - 2 >= 0)
				{
					dp[u][j][0] = max(dp[u][j][0], dp[u][j - k - 2][0] + dp[v][k][0]);
					dp[u][j][1] = max(dp[u][j][1], dp[u][j - k - 2][1] + dp[v][k][0]);
				}
				dp[u][j][1] = max(dp[u][j][1], dp[u][j - k - 1][0] + dp[v][k][1]);
			}
	}
}

int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
		memset(head, -1, sizeof(head));
		num = 0;
		for (int i = 1; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);
		}

		memset(vis, false, sizeof(vis));
		memset(dp, 0, sizeof(dp));
		dfs(1);
		printf("%d\n", max(dp[1][m][0], dp[1][m][1]));
	}
	return 0;
}