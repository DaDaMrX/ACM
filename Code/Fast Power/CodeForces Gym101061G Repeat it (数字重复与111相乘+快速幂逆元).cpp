// CodeForces Gym101061G Repeat it (数字重复与111相乘+快速幂逆元)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
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

ll inverse(ll a, ll mod)
{
    ll x, y;
    ext_gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

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

char s[15];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll m;
        scanf("%I64d%s", &m, s);
        int len = strlen(s);
        ll n = atoi(s);
        ll a = power(10, len, mod);
        a = power(a, m, mod);
        a = (a - 1) % mod;
        ll b = power(10, len, mod) - 1;
        ll inb = inverse(b, mod);
        ll ans = a * inb % mod;
        ans = ans * n % mod;
        printf("%I64d\n", ans);
    }
    return 0;
}
