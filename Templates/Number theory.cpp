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

int stoimod(char s[], int len, int m)
{
	long long ans = (s[0] - '0') % m;
	for (int i = 1; i < len; i++)
	{
		ans = (ans * 10 + s[i] - '0') % m;
	}
	return ans;
}

int power(long long a, int n, int m)
{
	long long ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}