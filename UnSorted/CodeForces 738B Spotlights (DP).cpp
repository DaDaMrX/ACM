/*
CodeForces 738B Spotlights (DP)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, m;
int map[N][N];

int l[N][N], r[N][N], u[N][N], d[N][N];
int ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	
	for (int i = 1; i <= n; i++)
	{
		l[i][1] = 0;
		for (int j = 2; j <= m; j++)
			l[i][j] = l[i][j - 1] + map[i][j - 1];
		r[i][m] = 0;
		for (int j = m - 1; j >= 1; j--)
			r[i][j] = r[i][j + 1] + map[i][j + 1];
	}
	for (int j = 1; j <= m; j++)
	{
		u[1][j] = 0;
		for (int i = 2; i <= n; i++)
			u[i][j] = u[i - 1][j] + map[i - 1][j];
		d[n][j] = 0;
		for (int i = n - 1; i >= 1; i--)
			d[i][j] = d[i + 1][j] + map[i + 1][j];
	}

	ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j]) continue;
			if (l[i][j]) ans++;
			if (r[i][j]) ans++;
			if (u[i][j]) ans++;
			if (d[i][j]) ans++;
		}
	printf("%d\n", ans);
	return 0;
}
