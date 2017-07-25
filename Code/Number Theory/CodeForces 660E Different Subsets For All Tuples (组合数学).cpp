#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 1e6 + 10;

ll f[N], g[N];

void init(int n, int m)
{
	f[0] = g[0] = 1;
	int t = 2 * m - 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * m % mod;
		g[i] = g[i - 1] * t % mod;
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init(n, m);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + f[n - i + 1] * g[i - 1] % mod) % mod;
	ans = (ans + f[n]) % mod;
	printf("%I64d\n", ans);
	return 0;
}