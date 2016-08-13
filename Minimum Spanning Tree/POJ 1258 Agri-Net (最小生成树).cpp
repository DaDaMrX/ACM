#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int map[N][N], dis[N];
bool vis[N];
int n;
int prim()
{
	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;
	memset(vis, true, sizeof(vis));
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int mini = -1;
		for (int j = 1; j <= n; j++)
			if (vis[j] && (mini == -1 || dis[j] < dis[mini]))
				mini = j;
		vis[mini] = false;
		ans += dis[mini];
		for (int j = 1; j <= n; j++)
			if (vis[j] && map[mini][j] < dis[j])
				dis[j] = map[mini][j];
	}
	return ans;
}
int main()
{
	while (~scanf("%d", &n) && n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);
		printf("%d\n", prim());
	}
	return 0;
}