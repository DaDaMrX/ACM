#include <cstdio>
#include <cstring>
#define N 110
#define INF 0x7f7f7f7f
int map[N][N], dis[N];
bool vis[N];
int n, start, finish;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	memset(vis, true, sizeof(vis));
	for (int i = 2; i <= n; i++)
	{
		int mini = -1;
		for (int j = 1; j <= n; j++)
			if (vis[j] && (mini == -1 || dis[j] < dis[mini])) mini = j;
		vis[mini] = false;
		for (int j = 1; j <= n; j++)
			if (vis[j] && map[mini][j] < INF && dis[mini] + map[mini][j] < dis[j])
				dis[j] = dis[mini] + map[mini][j];
	}
}
int main()
{
	scanf("%d%d%d", &n, &start, &finish);
	memset(map, 0x7f, sizeof(map));
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		int to;
		scanf("%d", &to);
		map[i][to] = 0;
		for (int j = 2; j <= k; j++)
		{
			to;
			scanf("%d", &to);
			map[i][to] = 1;
		}
	}
	dijkstra(start);
	if (dis[finish] < INF) printf("%d\n", dis[finish]);
	else printf("-1\n");
	return 0;
}