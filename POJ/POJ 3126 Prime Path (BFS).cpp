#include <cstdio>
#include <cstring>
#define N 25
#define INF 0x7fffffff
int map[N][N];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int w, h;
int min;
int startx, starty, goalx, goaly;
bool border(int x, int y)
{
	if (x < 1 || x > h || y < 1 || y > w) return false;
	return true;
}
void dfs(int x, int y, int step)
{
	if (step > 10) return;
	int xx, yy;
	for (int i = 0; i < 4; i++)
	{
		xx = x + dx[i]; yy = y + dy[i];
		if (map[xx][yy] == 1 || !border(xx, yy)) continue;
		while (!map[xx][yy] && border(xx, yy))
			xx += dx[i], yy += dy[i];
		if (!border(xx, yy)) continue;
		if (map[xx][yy] == 3)
			if (step < min) min = step;
		if (map[xx][yy] == 1)
		{
			map[xx][yy] = 0;
			xx -= dx[i], yy -= dy[i];
			dfs(xx, yy, step + 1);
			xx += dx[i], yy += dy[i];
			map[xx][yy] = 1;
		}
	}
}
int main()
{
	while (scanf("%d%d", &w, &h), w)
	{
		min = INF;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2) startx = i, starty = j, map[i][j] = 0;
				if (map[i][j] == 3) goalx = i, goaly = j;
			}
		dfs(startx, starty, 1);
		if (min == INF) printf("-1\n");
		else printf("%d\n", min);
	}
	return 0;
}
