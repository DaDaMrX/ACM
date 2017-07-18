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
	for (int cas = 1; cas <= T; cas++)
	{
		int n;
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int num = 2 * n / i - 1;
			ll a = power(2, num, mod) - 1;
			ll b = power(2, 2 * n - i - num, mod);
			ans = (ans + a * b % mod) % mod;
		}
		printf("Case %d: %lld\n", cas, ans);
	}	
	return 0;
}
