#include <cstdio>
inline int lowbit(int x) { return x & -x; }
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int ans = 0;
		while (n)
		{
			n -= lowbit(n);
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}