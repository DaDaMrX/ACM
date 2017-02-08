/*
HDU 1559 最大子矩阵 (矩阵前缀和)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int m, n, x, y;
int a[N][N], sum[N][N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &m, &n, &x, &y);
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
			}

		int ans = 0;
		for (int i = 0; i <= m - x; i++)
			for (int j = 0; j <= n - y; j++)
			{
				int total = sum[i + x][j + y] - sum[i + x][j] - sum[i][j + y] + sum[i][j];
				ans = max(ans, total);
			}
		printf("%d\n", ans);
	}
	return 0;
}