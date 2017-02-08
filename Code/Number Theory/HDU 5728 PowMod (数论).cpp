/*
HDU 5728 PowMod (数论)
第一步求k较复杂
第二步求ans用欧拉函数降幂，写出递归公式
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;

int n, m, p, k;
int phi[N], s[N];
int euler[N];

int prime[N];
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

void init(int n)
{
	get_euler(n);
	s[1] = phi[1];
	for (int i = 2; i <= n; i++)
		s[i] = (s[i - 1] + phi[i]) % mod;
}

ll f(int n, int m)
{
	if (m < 1) return 0;
	if (m == 1) return phi[n];
	if (n == 1) return s[m];
	if (phi[n] == n - 1) return (phi[n] * f(1, m) % mod + f(n, m / n)) % mod;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return (phi[i] * f(n / i, m) % mod + f(n, m / i)) % mod;
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

int g(int p)
{
	if (p == 1) return 0;
	return power(k, g(phi[p]) + phi[p], p);
}

int main()
{
	init(N);
	while (~scanf("%d%d%d", &n, &m, &p))
	{
		k = f(n, m);
		printf("%d\n", g(p));
	}
	return 0;
}