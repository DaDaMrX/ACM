#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 1e6 + 10;

ll sum[N];
void init()
{
	sum[0] = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		sum[i] = 1ll * (i - 1) * (i - 2) / 2 % mod;
		sum[i] = (sum[i - 1] + sum[i]) % mod;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	init();
	while (T--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = ((C[y] - C[x - 1]) % mod + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}