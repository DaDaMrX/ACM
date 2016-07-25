#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1510;
struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;
int n;
int dp[N][2];
bool vis[N];
void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}
void dfs(int u)
{
	vis[u] = true;
	dp[u][0] = 1;
	dp[u][1] = 0;
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if (vis[v]) continue;
		dfs(v);
		dp[u][0] += min(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
}
int main()
{
	while (~scanf("%d", &n))
	{
		memset(head, -1, sizeof(head));
		num = 0;
		for (int i = 0; i < n; i++)
		{
			int u, sum;
			scanf("%d:(%d)", &u, &sum);
			for (int j = 0; j < sum; j++)
			{
				int v;
				scanf("%d", &v);
				add(u, v);
				add(v, u);
			}
		}
		memset(vis, false, sizeof(vis));
		dfs(0);
		printf("%d\n", min(dp[0][0], dp[0][1]));
	}
	return 0;
}