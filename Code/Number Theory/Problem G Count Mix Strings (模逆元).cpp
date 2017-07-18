//Problem G Count Mix Strings (模逆元)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;

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

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll n, m;
		scanf("%I64d%I64d", &n, &m);
		ll s = n + m;
		ll fn, fm, fnm;
		ll f = 1;
		for (int i = 1; i <= s; i++)
		{
			f = f * i % mod;
			if (i == n) fn = f;
			if (i == m) fm = f;
			if (i == s) fnm = f;
		}

		ll vfn = power(fn, mod - 2, mod);
		ll vfm = power(fm, mod - 2, mod);
		ll ans = fnm * vfn % mod * vfm % mod;
		printf("%I64d\n", ans);
	}
	return 0;
}
