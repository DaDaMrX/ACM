map<ll, int> factor;

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

int main()
{
	get_prime();
	
	int n;
	factor.clear();
	get_factor(n);
}
