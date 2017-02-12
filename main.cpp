#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 10;
const int mod = 1e9 + 7;

int n, m;
int dp[N][N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int j = 1; j <= m; j++) dp[0][j] = 1;
		for (int i = 1; i <= n; i++) dp[i][0] = 1;
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
