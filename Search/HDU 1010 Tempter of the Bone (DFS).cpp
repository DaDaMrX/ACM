#include <cstdio>
#include <cstring>
#include <cmath>
#define N 10
bool map[N][N];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m, t;
int startx, starty, finishx, finishy;
bool dfs(int x, int y, int step)
{
	if (step == t)
	{
		if (x == finishx && y == finishy) return true;
		else return false;
	}
	map[x][y] = false;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
		if (!map[xx][yy]) continue;
		if (dfs(xx, yy, step + 1)) return true;
	}
	map[x][y] = true;
	return false;
}
int main()
{
	while (scanf("%d%d%d", &n, &m, &t), n)
	{
		getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				char c = getchar();
				map[i][j] = c == 'X' ? false : true;
				if (c == 'S') startx = i, starty = j;
				if (c == 'D') finishx = i, finishy = j;
			}
			getchar();
		}
		int shortest = abs(finishx - startx) + abs(finishy - starty);
		if (t < shortest || (t - shortest) & 1)
		{
			printf("NO\n");
			continue;
		}
		if (dfs(startx, starty, 0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
