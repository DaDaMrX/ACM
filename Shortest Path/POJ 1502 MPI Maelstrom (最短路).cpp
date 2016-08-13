#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
#define N 110
#define INF 0x3f3f3f3f
int map[N][N], dis[N];
bool vis[N];
int n;
const int start = 1;
void SPFA()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	vis[start] = true;
	queue<int> q;
	while (!q.empty()) q.pop();
	q.push(start); vis[start] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (int i = 1; i <= n; i++)
			if ( map[u][i] < INF && dis[u] + map[u][i] < dis[i])
			{
				dis[i] = dis[u] + map[u][i];
				if (!vis[i]) q.push(i), vis[i] = true;
			}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			char s[10];
			scanf("%s", s);
			if (s[0] == 'x') map[i][j] = map[j][i] = INF;
			else map[i][j] = map[j][i] = atoi(s);
		}
		map[i][i] = 0;
	}
	SPFA();
	int max = 0;
	for (int i = 2; i <= n; i++)
		if (dis[i] > max) max = dis[i];
	printf("%d\n", max);
	return 0;
}