/*
Codeforces 615D Multipliers (组合数学)
1.因子积公式
2.用map会T，能用数组先用数组
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n, m;
int num[N], p[N];
ll left[N], right[N];

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
	scanf("%d", &n);
	memset(num, 0, sizeof(num));
	m = 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		if (!num[t]) p[++m] = t;
		num[t]++;
	}

	left[0] = 1; left[1] = num[p[1]] + 1;
	for (int i = 2; i <= m; i++) left[i] = left[i - 1] * (num[p[i]] + 1) % (mod - 1);
	right[m + 1] = 1; right[m] = num[p[m]] + 1;
	for (int i = m - 1; i >= 1; i--) right[i] = right[i + 1] * (num[p[i]] + 1) % (mod - 1);

	ll ans = 1;
	for (int i = 1; i <= m; i++)
	{
		ll exp = (ll)num[p[i]] * (num[p[i]] + 1) / 2 % (mod - 1);
		exp = exp * left[i - 1] % (mod - 1) * right[i + 1] % (mod - 1);
		ans = ans * power(p[i], exp, mod) % mod;
	}

	printf("%I64d\n", ans);
	return 0;
}