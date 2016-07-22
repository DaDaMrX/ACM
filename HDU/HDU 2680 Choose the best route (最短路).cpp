#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x7f7f7f7f;
int map[N][N], dis[N];
bool vis[N];
int n, m, s, w, ans;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i < n; i++)
	{
		int u = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (u == -1 || dis[j] < dis[u])) u = j;
		vis[u] = true;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && map[u][j] < INF)
				dis[j] = min(dis[j], dis[u] + map[u][j]);
	}
}
int main()
{
	while (~scanf("%d%d%d", &n, &m, &s))
	{
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= m; i++)
		{
			int p, q, t;
			scanf("%d%d%d", &p, &q, &t);
			if (t < map[q][p]) map[q][p] = t;
		}
		dijkstra(s);
		scanf("%d", &w);
		ans = INF;
		for (int i = 1; i <= w; i++)
		{
			int to;
			scanf("%d", &to);
			if (dis[to] < ans) ans = dis[to];
		}
		if (ans == INF) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}