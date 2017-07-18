/********************************************************************************
Problem A. After Two Hares (前缀和矩阵)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2510;

int n, m;
char map[N][N];
int row[N][N], col[N][N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		row[i][0] = 0;
		for (int j = 1; j <= m; j++) 
			row[i][j] = map[i][j] == '#' ? row[i][j - 1] + 1 : row[i][j - 1];
	}
	for (int j = 1; j <= m; j++)
	{
		col[0][j] = 0;
		for (int i = 1; i <= n; i++)
			col[i][j] = map[i][j] == '#' ? col[i - 1][j] + 1 : col[i - 1][j];
	}

	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2) swap(x1, x2), swap(y1, y2);
		if (y1 < y2)
		{
			int up = row[x1][y2] - row[x1][y1];
			int down = row[x2][y2] - row[x2][y1];
			int left = col[x2][y1] - col[x1][y1];
			int right = col[x2][y2] - col[x1][y2];
			printf("%s\n", !up && !right && map[x1][y2] == '.' || !left && !down && map[x2][y1] == '.' ? "YES" : "NO");
		}
		else
		{
			int up = row[x1][y1] - row[x1][y2];
			int down = row[x2][y1] - row[x2][y2];
			int left = col[x2][y2] - col[x1][y2];
			int right = col[x2][y1] - col[x1][y1];
			printf("%s\n", !up && !left && map[x1][y2] == '.' || !right && !down && map[x2][y1] == '.' ? "YES" : "NO");
		}
	}
	return 0;
}
