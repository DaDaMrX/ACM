#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
#define INF 0x7f7f7f7f
struct node
{
	int d, p;
} map[N][N];
int dis[N], pri[N];
bool vis[N];
int n, m, s, t, mindis, minpri;
void dijkstra(int start)
{
	memset(vis, true, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	memset(pri, 0x7f, sizeof(pri));
	dis[start] = 0; pri[start] = 0;
	for (int i = 2; i <= n; i++)
	{
		int mini = -1;
		for (int j = 1; j <= n; j++)
			if (vis[j])
				if (mini == -1 || dis[j] < dis[mini] || (dis[j] == dis[mini] && pri[j] < pri[mini]))
					mini = j;
		vis[mini] = false;
		for (int j = 1; j <= n; j++)
			if (map[mini][j].d < INF && dis[mini] + map[mini][j].d < dis[j])
			{
				dis[j] = dis[mini] + map[mini][j].d;
				pri[j] = pri[mini] + map[mini][j].p;
			}
			else if (dis[mini] + map[mini][j].d == dis[j] && map[mini][j].p < INF && pri[mini] + map[mini][j].p < pri[j])
			{
				pri[j] = pri[mini] + map[mini][j].p;
			}
	}
}
int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= m; i++)
		{
			int a, b, d, p;
			scanf("%d%d%d%d", &a, &b, &d, &p);
			if (d < map[a][b].d || (d == map[a][b].d && p < map[a][b].p))
			{
				map[a][b].d = map[b][a].d = d;
				map[a][b].p = map[b][a].p = p;
			}
		}
		scanf("%d%d", &s, &t);
		dijkstra(s);
		printf("%d %d\n", dis[t], pri[t]);
	}
	return 0;
}