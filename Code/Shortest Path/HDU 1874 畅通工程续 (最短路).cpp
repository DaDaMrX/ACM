#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 210
#define INF 0x3f3f3f3f
int map[N][N], dis[N];
bool vis[N];
int n, m, start, finish;
int SPFA()
{
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0;
	queue<int> q;
	while (!q.empty()) q.pop();
	q.push(start); vis[start] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (int i = 0; i < n; i++)
			if (map[u][i] < INF && dis[u] + map[u][i] < dis[i])
			{
				dis[i] = dis[u] + map[u][i];
				if (!vis[i]) q.push(i), vis[i] = true;
			}
	}
	return dis[finish];
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		memset(map, 0x3f, sizeof(map));
		for (int i = 1; i <= m; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			if (w < map[a][b]) map[a][b] = map[b][a] = w;
		}
		scanf("%d%d", &start, &finish);
		int ans = SPFA();
		if (ans < INF) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}