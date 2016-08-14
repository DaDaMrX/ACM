#include <cstdio>
int main()
{
	int x = 2;
	int a, q;
	scanf("%d%d", &a, &q);
	int ans = 1;
	while (a)
	{
		if (a & 1) ans = ans * x % q;
		x = x * x % q;
		a /= 2;
	}
	printf("%d\n", ans);
	return 0;
}