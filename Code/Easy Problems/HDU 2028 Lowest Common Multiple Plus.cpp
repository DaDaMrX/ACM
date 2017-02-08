#include <cstdio>
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
	int g = gcd(a, b);
	return (a / g) * (b / g) * g;
}
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int ans = 1, a;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d\n", &a);
			ans = lcm(ans, a);
		}
		printf("%d\n", ans);
	}
	return 0;
}