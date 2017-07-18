// CodeForces Gym101147H Commandos (DP)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 15;

int dp[N][N][N];

int main()
{
	freopen("commandos.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			int f, x, y, h;
			scanf("%d%d%d%d", &f, &x, &y, &h);
			dp[f][x][y] = h;
		}
		for (int k = 10; k >= 1; k--)
			for (int i = 1; i <= 10; i++)
				for (int j = 1; j <= 10; j++)
				{
					int maxx = max(dp[k + 1][i][j], dp[k][i - 1][j]);
					maxx = max(maxx, dp[k][i][j - 1]);
					dp[k][i][j] += maxx;
				}
		printf("%d\n", dp[1][10][10]);
	}
	return 0;
}
