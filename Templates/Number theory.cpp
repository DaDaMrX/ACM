int gcd(int a, int b)
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

ll inverse(ll a, ll mod)
{
    ll x, y;
    ext_gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

// 线性筛逆元
ll inv[N];
void get_inv(int n, int mod)
{
    inv[1] = 1;
    for (int i = 2; i < n; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
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


const int nn = 2;
struct Matrix
{
    ll a[5][5], n;
    Matrix(ll x = 0, ll b = 0, ll c = 0, ll d = 0)
    {
        n = 2;
        a[1][1] = x; a[1][2] = b;
        a[2][1] = c; a[2][2] = d;
    }
    ll* operator[](int i)
    {
        return a[i];
    }
};

Matrix operator*(Matrix A, Matrix B)
{
    int n = A.n;
    Matrix C;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
    return C;
}

Matrix power(Matrix A, ll n, ll mod)
{
    Matrix C(1, 0, 0, 1);
    while (n)
    {
        if (n & 1) C = C * A;
        A = A * A;
        n >>= 1;
    }
    return C;
}


Matrix operator-(Matrix A, Matrix B)
{
    ll n = A.n;
    Matrix C;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][j] = ((A[i][j] - B[i][j]) % mod + mod) % mod;
    return C;
}

Matrix operator+(Matrix A, Matrix B)
{
    ll n = A.n;
    Matrix C;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            C[i][j] = (A[i][j] + B[i][j]) % mod;
    return C;
}

//判素数 O(sqrt(n))
bool prime(int n)
{
	if (n == 0 || n == 1) return false;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return false;
	return true; 
}

// 素因子分解 O(sqrt(n))
// fact[i]表示第i个素因子，num[i]表示第i个素因子的数量
// 如果之前晒过素数，可以用prime[i]代替i，直接枚举素数，会更快
int fact[10], num[10], cnt;
void factorize(int n)
{
    cnt = 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            fact[cnt] = i; num[cnt] = 0;
            while (n % i == 0) n /= i, num[cnt]++;
            cnt++;
        }
    if (n > 1) fact[cnt] = n, num[cnt++] = 1;
}

//求欧拉函数值 O(sqrt(n))
//核心为素分解
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

//大数取模 O(n)
//输入时用到
int mod(char s[], int len, int m)
{
	long long ans = 0;
	for (int i = 0; i < len; i++)
		ans = ((ans * 10) % m + (s[i] - '0') % m) % m;
	return ans;
}

//大数分段取模*
//输入特别大时用到
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
