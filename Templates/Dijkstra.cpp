/*
Djikstra algorithm

输入: map[N][N], n, start
借助：vis[N]
输出: dis[N]

过程:
	n-1次循环
		找到最近点
		标记
		松弛

注意: 两点距离不连通时距离为INF，可以用来比较，但不能想加，会溢出称为负值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20
#define INF 0x7f7f7f7f
int map[N][N], dis[N];
bool vis[N];
int n, m;
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
			if (map[mini][j] < INF)	dis[j] = min(dis[j], dis[mini] + map[mini][j]);
	}
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		memset(map, 0x7f, sizeof(map));
		for (int i = 1; i <= m; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			if (w < map[a][b]) map[a][b] = map[b][a] = w;
		}
		dijkstra(1);
		for (int i = 1; i <= n; i++) printf("%d: %d\n", i, dis[i]);
	}
	return 0;
}

/*
Sample Input
7 10
1 2 2
2 5 10
5 7 5
1 3 5
2 3 4
2 4 6
5 6 3
6 7 9
3 4 2
4 6 1

Sample Output
1: 0
2: 2
3: 5
4: 7
5: 11
6: 8
7: 16

*/
