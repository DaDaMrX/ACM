#include <cstdio>
inline int lowbit(int x) { return x & -x; }
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int a = (1 << m) - 1 & n;
		long long ans = 0;
		while (a)
		{
			a -= lowbit(a);
			ans++;
		}
		ans += n >> m;
		printf("%lld\n", ans);
	}
	return 0;
}