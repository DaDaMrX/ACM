/*
POJ 2891 Strange Way to Express Integers (数论+中国剩余定理)
中国剩余定理，一元线性同余方程组，模不互素情况
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

ll extgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	else
	{
		ll d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return d;
	}
}

int main()
{
	int k;
	while (~scanf("%d", &k))
	{
		bool flag = true;
		ll a1, r1;
		scanf("%lld%lld\n", &a1, &r1);
		for (int i = 2; i <= k; i++)
		{
			ll a2, r2;
			scanf("%lld%lld", &a2, &r2);
			if (!flag) continue;
			ll x, y;
			ll g = extgcd(a1, a2, x, y);
			if ((r2 - r1) % g)
			{
				flag = false;
				continue;
			}
			x = x * ((r2 - r1) / g);
			ll mod = a2 / g;
			x = ((x % mod) + mod) % mod;
			r1 = r1 + x * a1;
			a1 = a1 * a2 / g;
			r1 = ((r1 % a1) + a1) % a1;
		}
		
		if (flag) printf("%lld\n", r1);
		else printf("-1\n");
	}
	return 0;
}