#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;
bool vis[N];
int n;

int dp[N][N], bug[N], p[N];
int m;

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

void dfs(int u)
{
	vis[u] = true;
	int cost = (bug[u] + 19) / 20;
	for (int j = cost; j <= m; j++) dp[u][j] = p[u];
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if (vis[v]) continue;
		dfs(v);
		for (int j = m; j >= cost; j--)
			for (int k = 1; k <= j - cost; k++)
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
	}
}

int main()
{
	while (scanf("%d%d", &n, &m), ~n)
	{
		for (int i = 1; i <= n; i++) scanf("%d%d", &bug[i], &p[i]);
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

		if (!m)
		{
			printf("0\n");
			continue;
		}

		memset(dp, 0, sizeof(dp));
		dfs(1);
		printf("%d\n", dp[1][m]);
	}
	return 0;
}