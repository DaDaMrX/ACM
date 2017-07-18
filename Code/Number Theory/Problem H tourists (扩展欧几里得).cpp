//Problem H tourists (扩展欧几里得)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

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

int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		int c1, n1, c2, n2;
		scanf("%d%d%d%d", &c1, &n1, &c2, &n2);
		if (n % gcd(n1, n2))
		{
			printf("failed\n");
			continue;
		}
		ll x, y;
		ll g = ext_gcd(n1, n2, x, y);
		ll c = n / g;
		x *= c; y *= c;
		if ((double)c1 / n1 < (double)c2 / n2)
		{
			ll mod = n1 / g;
			ll yy = (y % mod + mod) % mod;
			ll k = (y - yy) / mod;
			y = yy;
			x += k * (n2 / g);
			if (x < 0)
			{
				printf("failed\n");
				continue;
			}
			printf("%I64d %I64d\n", x, y);
		}
		else
		{
			ll mod = n2 / g;
			ll xx = (x % mod + mod) % mod;
			ll k = (x - xx) / mod;
			x = xx;
			y += k * (n1 / g);
			if (y < 0)
			{
				printf("failed\n");
				continue;
			}
			printf("%I64d %I64d\n", x, y);
		}
	}
	return 0;
}
