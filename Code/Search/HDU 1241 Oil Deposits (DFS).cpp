#include <cstdio>
#include <cstring>
#define N 110
bool map[N][N];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int m, n, ans;
void dfs(int x, int y)
{
	map[x][y] = false;
	for (int i = 0; i < 8; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > m || yy < 1 || yy > n || !map[xx][yy]) continue;
		dfs(xx, yy);
	}
}
int main()
{
	while (scanf("%d%d", &m, &n), m)
	{
		char c = getchar();
		while (c != '\n') c = getchar();
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				char c = getchar();
				map[i][j] = c == '@' ? true : false;
			}
			getchar();
		}
		int ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j]) dfs(i, j), ans++;
		printf("%d\n", ans);
	}
	return 0;
}
