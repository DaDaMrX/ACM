#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 15;
const int mod = 1e9;

int n, m;
int map[N];
int dp[N][1 << N];

int main()
{
	scanf("%d%d", &m, &n);
	memset(map, 0, sizeof(map));
	for (int i = 0; i < m; i++)
		for (int j = n - 1; j >= 0; j--)
		{
			int x;
			scanf("%d", &x);
			map[i] += (x << j);
		}

	memset(dp, 0, sizeof(dp));
	for (int S = 0; S < (1 << n); S++)
		if (!(S & S << 1) && ((map[0] & S) == S)) dp[0][S] = 1;

	for (int i = 1; i < m; i++)
		for (int S = 0; S < (1 << n); S++)
			if (!(S & S << 1) && ((map[i] & S) == S))
				for (int T = 0; T < (1 << n); T++)
					if (!(S & T) && ((map[i - 1] & T) == T))
						dp[i][S] = (dp[i][S] + dp[i - 1][T]) % mod;

	int ans = 0;
	for (int S = 0; S < (1 << n); S++)
		if (!(S & S << 1) && ((map[m - 1] & S) == S))
			ans = (ans + dp[m - 1][S]) % mod;
	printf("%d\n", ans);
	return 0;
}