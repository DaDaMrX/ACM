#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 2e5 + 10;

ll power(ll a, ll n, ll m)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}

int p[N], num[N], tot;
ll l[N], r[N];

int main()
{
	int n;
	scanf("%d", &n);
	memset(num, 0, sizeof(num));
	tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		if (num[t] == 0) p[++tot] = t;
		num[t]++;
	}
	l[0] = 1;
	for (int i = 1; i <= tot; i++) l[i] = l[i - 1] * (num[p[i]] + 1) % mod;
	r[tot + 1] = 1;
	for (int i = tot; i >= 1; i--) r[i] = r[i + 1] * (num[p[i]] + 1) % mod;
	ll ans = 1;
	for (int i = 1; i <= tot; i++)
	{
		ll e = (ll)num[p[i]] * (num[p[i]] + 1) / 2 % (mod - 1) * l[i - 1] % (mod - 1) * r[i + 1] % (mod - 1);
		ans = ans * power(p[i], e, mod) % mod;
	}
	printf("%I64d\n", ans);
	return 0;
}