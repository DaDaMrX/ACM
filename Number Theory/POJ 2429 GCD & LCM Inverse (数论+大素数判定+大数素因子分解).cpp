/*
POJ 2429 GCD & LCM Inverse (数论+素数判定Miller-Rabin+素因子分解Pollard-rho)
令g=gcd(a,b),l=lcm(a,b)，则有gcd(a/g,b/g)=1,(a/g)*(b/g)=l/g，
所以问题转化为求t=l/g所有的素因子和每个素因子对应的幂指数，
但由于t可能会非常大，所以正常的素因子分解会超时，
此处需要用Pollard-rho来分解大数，
而在素数判定时，同样的由于数会很大所以要用Miller-Rabin判定，
对于比较小的数可以首先打一个素数表来判断，
当对t素因子分解后，2^res枚举a/g应含的素因子（res为t的素因子数）更新最优解即可
PS：交C++ AC，交G++ WA
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

map<ll, int> factor;
map<ll, int>::iterator iter;

bool is_prime[N];
vector<int> prime;
void get_prime()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < N; i++)
		if (is_prime[i])
		{
			prime.push_back(i);
			for (int j = i; j < N; j += i) is_prime[j] = false;
		}
}

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll mod_mul(ll a, ll b, ll p)
{
	ll ans = 0ll;
	a %= p, b %= p;
	if (a > b) swap(a, b);
	while (b)
	{
		if (b & 1) ans = (ans + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ans;
}
ll mod_pow(ll a, ll b, ll p)
{
	ll ans = 1ll;
	a %= p;
	while (b)
	{
		if (b & 1) ans = mod_mul(ans, a, p);
		a = mod_mul(a, a, p);
		b >>= 1;
	}
	return ans;
}
int Times = 20;
bool witness(ll a, ll n)
{
	ll m = n - 1;
	int j = 0;
	while ((m & 1) == 0)
	{
		j++;
		m >>= 1;
	}
	ll x = mod_pow(a, m, n);
	if (x == 1 || x == n - 1) return false;
	while (j--)
	{
		x = mod_mul(x, x, n);
		if (x == n - 1) return false;
	}
	return true;
}
bool Miller_Rabin(ll n)
{
	srand(time(0));
	if (n < 2) return 0;
	if (n == 2) return 1;
	if ((n & 1) == 0) return 0;
	for (int i = 0;i < Times;i++)
	{
		ll a = rand() % (n - 1) + 1;
		if (witness(a, n)) return false;
	}
	return true;
}
ll Pollard_Rho(ll n, int c)
{
	ll x = 2, y = 2, d = 1;
	while (d == 1)
	{
		x = mod_mul(x, x, n) + c;
		y = mod_mul(y, y, n) + c;
		y = mod_mul(y, y, n) + c;
		d = gcd((x - y >= 0 ? x - y : y - x), n);
	}
	if (d == n) return Pollard_Rho(n, c + 1);
	return d;
}
bool Is_Prime(ll n)
{
	if (n < N && is_prime[n] || n >= N && Miller_Rabin(n)) return true;
	return false;
}
void get_factor(ll n)
{
	if (Is_Prime(n))
	{
		factor[n]++;
		return;
	}
	for (int i = 0; i < prime.size() && prime[i] <= n; i++)
		if (n % prime[i] == 0)
		{
			while (n%prime[i] == 0)
			{
				factor[prime[i]]++;
				n /= prime[i];
			}
		}
	if (n != 1)
	{
		if (Is_Prime(n))
			factor[n]++;
		else
		{
			ll p = Pollard_Rho(n, 1);
			get_factor(p);
			get_factor(n / p);
		}
	}
}


vector<ll> fact;
int main()
{
	ll g, l;
	get_prime();
	while (~scanf("%lld%lld", &g, &l))
	{
		ll t = l / g;
		factor.clear();
		get_factor(t);

		fact.clear();
		for (iter = factor.begin(); iter != factor.end(); iter++)
		{
			ll s = 1;
			while (iter->second)
			{
				s *= iter->first;
				iter->second--;
			}
			fact.push_back(s);
		}

		ll x = 1, y = t, minx = t + 1;
		int states = 1 << factor.size();
		for (int S = 0; S < states; S++)
		{
			ll xx = 1;
			for (int i = 0; i < fact.size(); i++)
				if (S & (1 << i)) xx *= fact[i];
			ll yy = t / xx;
			if (xx < yy && xx + yy < minx)
				x = xx, y = yy, minx = xx + yy;
		}

		printf("%lld %lld\n", x * g, y * g);
	}
	return 0;
}