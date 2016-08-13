#include <cstdio>
#include <cstring>
#define N 110
#define INF 0x7fffffff
int map[N][N], dis[N];
bool vis[N];
int n;
int prim()
{
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	for (int i = 1; i <= n; i++) dis[i] = map[1][i];
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		int minx = INF, mini;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < minx) minx = dis[mini = j];
		ans += dis[mini]; vis[mini] = true;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && map[mini][j] < dis[j]) dis[j] = map[mini][j];
	}
	return ans;
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++) map[i][i] = 0;
		int sum = n * (n - 1) / 2;
		for (int i = 1; i <= sum; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			map[a][b] = map[b][a] = w;
		}
		printf("%d\n", prim());
	}
	return 0;
}