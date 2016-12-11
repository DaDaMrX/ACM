/********************************************************************************
Problem A. Innovative Experiment (置换群)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

ll k;

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
	int Times = 20;
	for (int i = 0;i < Times;i++)
	{
		ll a = rand() % (n - 1) + 1;
		if (witness(a, n)) return false;
	}
	return true;
}

ll factor[N];
int t;
ll sum;
void get_factor()
{
	t = 0; 
	sum = 0;
	ll s = sqrt(k);
	for (ll i = 2; i <= s; i++)
	{
		if (k % i == 0)
		{
			factor[t] = 1;
			while (k % i == 0)
			{
				k /= i;
				factor[t] *= i;
			}
			sum += factor[t];
			t++;
			if (sum > (ll)100000) 
			{
				t = -1;
				return;
			}
			s = sqrt(k);
		}
		if (i > (ll)100000)
		{
			t = -1;
			return;
		}
	}
	if (k > 1)
	{
		factor[t] = k;
		sum += factor[t];
		t++;
		if (sum > (ll)100000)
		{
			t = -1;
			return;
		} 
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%I64d", &k);

	if (k == 1)
	{
		printf("1\n1\n");
		return 0;
	}

	if (k <= (ll)100000)
	{
		printf("%d\n", k);
		for (int i = 2; i <= k; i++) printf("%d ", i);
		printf("1\n");
		return 0;
	}

	if (Miller_Rabin(k))
	{
		printf("No solution\n");
		return 0;
	}

	get_factor();

	if (t == -1)
	{
		printf("No solution\n");
		return 0;
	}
	
	printf("%I64d\n", sum);
	ll start = 0;
	for (int i = 0; i < t; i++)
	{
		ll tmp = ++start;
		for (int j = 1; j < factor[i]; j++) printf("%d ", ++start);
		printf("%d ", tmp);
	}
	printf("\n");
	return 0;
}
