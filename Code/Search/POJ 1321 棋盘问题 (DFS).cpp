#include <cstdio>
#include <cstring>
#define N 10
bool map[N][N], col[N];
int n, k, ans;
void dfs(int i, int row)
{
	if (i > k)
	{
		ans++;
		return;
	}
	if (row > n) return;
	for (int j = 1; j <= n; j++)
		if (map[row][j] && col[j])
		{
			col[j] = false;
			dfs(i + 1, row + 1);
			col[j] = true;
		}
	dfs(i, row + 1);
}
int main()
{
	while (scanf("%d%d", &n, &k), ~n)
	{
		char c = getchar();
		while (c != '\n') c = getchar();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				char c = getchar();
				map[i][j] = c == '#' ? true : false;
			}
			getchar();
		}
		memset(col, true, sizeof(col));
		ans = 0;
		dfs(1, 1);
		printf("%d\n", ans);
	}
	return 0;
}
