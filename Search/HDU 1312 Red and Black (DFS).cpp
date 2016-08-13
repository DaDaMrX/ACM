#include <cstdio>
#include <cstring>
#define N 25
bool map[N][N];
bool vis[N][N];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
int startx, starty;
int ans;
void dfs(int x, int y)
{
	vis[x][y] = false; ans++;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
		if (!map[xx][yy] || !vis[xx][yy]) continue;
		dfs(xx, yy);
	}
}
int main()
{
	while (scanf("%d%d", &m, &n), m)
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				char c = getchar();
				map[i][j] = (c == '#' ? false : true);
				if (c == '@') startx = i, starty = j;
			}
			getchar();
		}
		ans = 0;
		memset(vis, true, sizeof(vis));
		dfs(startx, starty);
		printf("%d\n", ans);
	}
	return 0;
}
