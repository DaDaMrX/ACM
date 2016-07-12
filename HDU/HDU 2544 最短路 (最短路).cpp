#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 110
#define INF 0x7fffffff
int map[N][N], dis[N];
bool vis[N];
int n, m;
const int start = 1;
int SPFA()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	queue<int> q;
	while (!q.empty()) q.pop();
	q.push(start); vis[start] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (int j = 1; j <= n; j++)
		{
			int sum = dis[u] + map[u][j];
			if (sum < dis[j])
			{
				dis[j] = sum;
				if (!vis[j]) q.push(j), vis[j] = true;
			}
		}
	}
	return dis[n];
}
int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= n; i++) map[i][i] = 0;
		int a, b, c;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}
		printf("%d\n", SPFA());
	}
	return 0;
}