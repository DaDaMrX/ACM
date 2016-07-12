#include <cstdio>
#include <cstring>
#define N 110
#define INF 0x7f7f7f7f
int map[N][N], dis[N];
bool vis[N];
int n, m;
int prim()
{
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	for (int i = 1; i <= n; i++) dis[i] = map[1][i];
	dis[1] = 0;
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		int minx = INF, mini;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < minx) 
				minx = dis[mini = j];
		if (minx == INF) return 0;
		ans += dis[mini];
		vis[mini] = true;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && map[mini][j] < dis[j]) 
				dis[j] = map[mini][j];
	}
	return ans;
}
int main()
{
	while (~scanf("%d%d", &m, &n), m)
	{
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= m; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			map[a][b] = map[b][a] = w;
		}
		int ans = prim();
		if (ans) printf("%d\n", ans);
		else printf("?\n");
	}
	return 0;
}