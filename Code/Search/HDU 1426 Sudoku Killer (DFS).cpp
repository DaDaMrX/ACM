#include <cstdio>
#include <cstring>
#define N 10
bool row[N][N], col[N][N], block[N][N];
int map[N][N];
int atob(int i, int j)
{
	return (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
}
bool find(int x, int y, int *pxx, int *pyy)
{
	while (x < N && y < N && map[x][y])
	{
		if (y == N - 1)
		{
			x++; y = 1;
		}
		else y++;
	}
	if (x == N) return false;
	*pxx = x; *pyy = y;
	return true;
}
bool dfs(int x, int y)
{
	for (int i = 1; i < N; i++)
	{
		if (!row[x][i] || !col[y][i] || !block[atob(x, y)][i]) continue;
		map[x][y] = i;
		row[x][i] = col[y][i] = block[atob(x, y)][i] = false;
		int xx, yy;
		if (!find(x, y, &xx, &yy)) return true;
		if (dfs(xx, yy)) return true;
		map[x][y] = 0;
		row[x][i] = col[y][i] = block[atob(x, y)][i] = true;
	}
	return false;
}
int main()
{
	char c;
	int cnt = 0;
	while (~(c = getchar()))
	{
		cnt++;
		if (cnt > 1) printf("\n");
		getchar();
		memset(row, true, sizeof(row));
		memset(col, true, sizeof(col));
		memset(block, true, sizeof(block));
		if (c == '?') map[1][1] = 0;
		else
		{
			int a = map[1][1] = c - '0';
			row[1][a] = col[1][a] = block[1][a] = false;
		}
		for (int i = 1; i < N; i++)
			for (int j = 1; j < N; j++)
			{
				if (i == 1 && j == 1) continue;
				char c = getchar(); getchar();
				if (c == '?') map[i][j] = 0;
				else
				{
					int a = map[i][j] = c - '0';
					row[i][a] = col[j][a] = block[atob(i, j)][a] = false;
				}
			}
		getchar();
		for (int i = 1; i < N; i++)
			for (int j = 1; j < N; j++)
				if (!map[i][j])
				{
					dfs(i, j);
					break;
				}
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < N - 1; j++) printf("%d ", map[i][j]);
			printf("%d\n", map[i][N - 1]);
		}
	}
	return 0;
}