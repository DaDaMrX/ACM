#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e2 + 10;

int n, a[N], dp[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) dp[i][i] = 1;
	for (int i = 1; i < n; i++) dp[i][i + 1] = a[i] == a[i + 1] ? 1 : 2;
	for (int len = 3; len <= n; len++)
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			dp[i][j] = dp[i + 1][j] + 1;
			if (a[i] == a[i + 1]) dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
			if (a[i] == a[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
			for (int k = i + 2; k < j; k++)
				if (a[i] == a[k])
					dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
		}
	printf("%d\n", dp[1][n]);
	return 0;
}
