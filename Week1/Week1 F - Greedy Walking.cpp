#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 60;
const int mod = 1e9 + 7;

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	ll d = ext_gcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

ll inv(ll a, ll mod)
{
    ll x, y;
    ext_gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

ll f[510];
int n, a[N], b[N];

void init(int n)
{
	f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
}

int main()
{
	init(500);
	while (~scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) scanf("%d", b + i);
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] = b[i] - a[i];
			sum += a[i];
		}	
		ll ans = f[sum];
		for (int i = 1; i <= n; i++)
			ans = ans * inv(f[a[i]], mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
