#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e7 + 7;
const int N = 1e4 + 10;

int sum[35][2];

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int n;
		scanf("%d", &n);
		memset(sum, 0, sizeof(sum));
		while (n--)
		{
			int x;
			scanf("%d", &x);
			for (int i = 0; i <= 31; i++) sum[i][(x >> i) & 1]++;
		}
		ll ans = 0;
		for (int i = 0; i <= 31; i++) ans = (ans + sum[i][0] * sum[i][1] % mod * 2) % mod;
		printf("Case %d: %lld\n", cas, ans);
	}
	return 0;
}