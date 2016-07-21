#include <cstdio>
long long multiply(long long a, long long b, long long m)
{
	long long ans = 0;
	while (a)
	{
		if (a % 2 == 1) ans = (ans + b) % m;
		a /= 2;
		b = (b << 1) % m;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long q, p, ans;
		scanf("%lld%lld", &q, &p);
		if (q & 1) ans = multiply((q - 1) / 2, (q - 2), p);
		else ans = multiply((q - 1), (q - 2) / 2, p);
		printf("%lld\n", ans);
	}
	return 0;
}