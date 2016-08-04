int extgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	else
	{
		int d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return d;
	}
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

//求欧拉函数值
int phi(int n)
{
	int ans = n;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
			s = sqrt(n);
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}


//线性筛欧拉函数*
int phi[N], prime[N];
void get_euler(int n)
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!phi[i]) phi[i] = i - 1, prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++)
		{
			if (i % prime[j]) phi[prime[j] * i] = phi[i] * (prime[j] - 1);
			else
			{
				phi[prime[j] * i] = phi[i] * prime[j];
				break;
			}
		}
	}
}

//大数取模
int mod(char s[], int len, int m)
{
	long long ans = 0;
	for (int i = 0; i < len; i++)
		ans = ((ans * 10) % m + (s[i] - '0') % m) % m;
	return ans;
}

//大数分段取模
int change(char s[], int len, int sum, int a[])
{
	int n = (len / sum) + (len % sum > 0);
	for (int i = n - 1, j = len - 1; i >= 0; i--)
	{
		a[i] = 0;
		int weight = 1;
		for (int k = 1; k <= sum; k++)
		{
			a[i] += (s[j] - '0') * weight;
			j--;
			weight *= 10;
			if (j < 0) break;
		}
	}
	return n;
}
int mod(int a[], int n, int sum, int m)
{
	int ans = 0;
	int weight = 1;
	for (int i = 1; i <= sum; i++) weight *= 10;
	for (int i = 0; i < n; i++)
		ans = ((ans * weight) % m + a[i] % m) % m;
	return ans;
}

//线性筛素数*
int mark[N], prime[N];
void get_prime(int n)
{
	memset(mark, 0, sizeof(mark));
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) mark[i] = prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++)
		{
			mark[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}

//阶乘素分解
map<int, int> factor;
map<int, int>::iterator iter;
void get_factor(int n)
{
	factor.clear();
	for (int i = 0; prime[i] <= n; i++)
		for (int j = prime[i]; j <= n; j *= prime[i])
			factor[prime[i]] += n / j;
}

//素分解
map<int, int> factor;
map<int, int>::iterator iter;
void get_factor(int n)
{
	factor.clear();
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				factor[i]++;
			}
			s = sqrt(n);
		}
	if (n > 1) factor[n]++;
}

//中国剩余定理 模不互素
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