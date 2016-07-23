#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 910;
int map[N][N];
int n, m;
void floyd()
{
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		memset(map, 0x7f, sizeof(map));
		while (m--)
		{
			int sum, a[N];
			scanf("%d", &sum);
			for (int i = 1; i <= sum; i++)
			{
				scanf("%d", &a[i]);
				for (int j = 1; j < i; j++)
					map[a[i]][a[j]] = map[a[j]][a[i]] = 1;
			}
		}
		floyd();
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j <= n; j++) sum += map[i][j];
			if (sum < ans) ans = sum;
		}
		printf("%d\n", 100 * ans / (n - 1));
	}
	return 0;
}