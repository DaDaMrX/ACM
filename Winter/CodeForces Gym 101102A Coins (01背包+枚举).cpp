//CodeForces Gym101102A Coins (01背包+枚举)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 160;
const int M = 160000;

int a1[N], dp1[M], a2[N], dp2[M];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, k, w;
		scanf("%d%d%d%d", &n, &m, &k, &w);

		int sum1 = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a1 + i);
			sum1 += a1[i];
		}
		sum1 = min(sum1, w);

		memset(dp1, 0, sizeof(dp1));
		dp1[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = sum1; j >= a1[i]; j--)
				dp1[j] = (dp1[j] + dp1[j - a1[i]]) % mod;
		}
		
		int sum2 = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", a2 + i);
			sum2 += a2[i];
		}
		sum2 = min(sum2, w);

		memset(dp2, 0, sizeof(dp2));
		dp2[0] = 1;
		for (int i = 1; i <= m; i++)
		{
			for (int j = sum2; j >= a2[i]; j--)
				dp2[j] = (dp2[j] + dp2[j - a2[i]]) % mod;
		}

		int ans = 0;
		for (int i = 0; i <= sum1; i++)
		{
			int j = w - i;
			if (abs(i - j) > k) continue;
			int sum = ((ll)dp1[i] * dp2[j]) % mod;
			ans = (ans + sum) % mod;
		}

		printf("%d\n", ans);
	}
	return 0;
}
