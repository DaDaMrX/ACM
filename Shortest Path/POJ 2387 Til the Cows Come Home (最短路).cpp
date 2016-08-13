#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff
#define N 1010
int map[N][N], dis[N];
bool vis[N];
int n, m;
int dijkstra()
{
	for (int i = 2; i <= n; i++)
	{
		int minx = INF, mini;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < minx) minx = dis[mini = j];
		vis[mini] = true;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) dis[j] = min(dis[mini] + map[mini][j], dis[j]);
	}
	return dis[1];
}
int main()
{
	scanf("%d%d", &m, &n);
	memset(map, 0x7f, sizeof(map));
	int a, b, w;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &w);
		if (w < map[a][b]) map[a][b] = map[b][a] = w;
	}
	for (int i = 1; i <= n; i++) dis[i] = map[n][i];
	dis[n] = 0;
	memset(vis, false, sizeof(vis));
	vis[n] = true;
	printf("%d\n", dijkstra());
	return 0;
}