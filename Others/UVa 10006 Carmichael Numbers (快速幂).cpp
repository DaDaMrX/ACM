#include <cstdio>
#include <cstring>
#define N 65010
bool prime[N];
int n;
void sieve()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < N; i++)
		if (prime[i])
			for (int j = i + i; j < N; j += i)
				prime[j] = false;
}
int power(long long a, int b, int c)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1) ans = ans * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return ans;
}
int main()
{
	sieve();
	while (scanf("%d", &n), n)
	{
		if (prime[n])
		{
			printf("%d is normal.\n", n);
			continue;
		}
		int i;
		for (i = 2; i < n; i++)
			if (power(i, n, n) != i) break;
		if (i < n) printf("%d is normal.\n", n);
		else printf("The number %d is a Carmichael number.\n", n);
	}
	return 0;
}