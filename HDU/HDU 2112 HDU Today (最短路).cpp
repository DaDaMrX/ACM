#include <cstdio>
#include <cstring>
#define N 160
#define INF 0x7f7f7f7f
char site[N][40];
int map[N][N], dis[N];
bool vis[N];
int n, ps;
int check(char s[])
{
	for (int i = 1; i <= ps; i++)
		if (strcmp(s, site[i]) == 0) return i;
	strcpy(site[++ps], s);
	return ps;
}
void dijkstra(int start)
{
	memset(vis, true, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	for (int i = 2; i <= ps; i++)
	{
		int mini = -1;
		for (int j = 1; j <= ps; j++)
			if (vis[j] && (mini == -1 || dis[j] < dis[mini])) mini = j;
		vis[mini] = false;
		for (int j = 1; j <= ps; j++)
			if (vis[j] && map[mini][j] < INF && dis[mini] + map[mini][j] < dis[j])
				dis[j] = dis[mini] + map[mini][j];
	}
}
int main()
{
	while (scanf("%d", &n), ~n)
	{
		memset(map, 0x7f, sizeof(map));
		char s1[40], s2[40];
		scanf("%s%s", s1, s2);
		ps = 0;
		check(s1);
		check(s2);
		for (int i = 1; i <= n; i++)
		{
			char s[40];
			scanf("%s", s);
			int from = check(s);
			scanf("%s", s);
			int to = check(s);
			int time;
			scanf("%d", &time);
			if (time < map[from][to]) 
				map[from][to] =map[to][from] = time;
		}
		if (strcmp(s1, s2) == 0)
		{
			printf("0\n");
			continue;
		}
		dijkstra(1);
		if (dis[2] < INF) printf("%d\n", dis[2]);
		else printf("-1\n");
	}
	return 0;
}