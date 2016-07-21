#include <cstdio>
#include <cstring>
int fastpow(long long a, int n, int m)
{
	int ans = 1;
	while (n > 0)
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
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d:\n", i);
		int x, m, k, c;
		scanf("%d%d%d%d", &x, &m, &k, &c);
		int ans = (fastpow(10, m, 9 * k) - 1) / 9 * x % k;
		if (ans == c) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}