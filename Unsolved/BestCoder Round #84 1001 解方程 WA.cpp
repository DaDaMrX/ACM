#include <cstdio>
#include <cmath>
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n, m;
		scanf("%lld%lld", &n, &m);
		if (m == 0)
		{
			printf("%lld\n", n);
			continue;
		}
		long long ans;
		long long t = (long long)log2(n);
		if (m < t)
		{
			ans = pow(2, t - m);
			n -= pow(2, t);
		}
		else ans = 0;
		while (n)
		{
			t = (long long)log2(n);
			n -= pow(2, t);
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}