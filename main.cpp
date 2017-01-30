#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int n, m, map[N][N];

void floyd()
{
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(map, 0x3f, sizeof(map));
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		map[u][v] = w;
	}
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) printf("%d ", map[i][j]);
		printf("\n");
	}
	return 0;
}

