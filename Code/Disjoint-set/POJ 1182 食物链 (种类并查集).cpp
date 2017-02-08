#include <cstdio>
#include <cstring>
#define N 50000
int fa[3 * N], deep[3 * N];
int n, k, ans;
void init(int n)
{
	for (int i = 1; i <= n; i++) fa[i] = i, deep[i] = 0;
}
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (deep[x] < deep[y]) fa[x] = y;
	else
	{
		fa[y] = x;
		if (deep[x] == deep[y]) deep[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	scanf("%d%d", &n, &k);
	init(n * 3);
	ans = 0;
	for (int i = 1; i <= k; i++)
	{
		int d, x, y;
		scanf("%d%d%d", &d, &x, &y);
		if (x < 1 || x > n || y < 1 || y > n || (d == 2 && x == y))
		{
			ans++;
			continue;
		}
		if (d == 1)
		{
			if (same(x, y + n) || same(y, x + n))
			{
				ans++;
				continue;
			}
			else
			{
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
			
		}
		if (d == 2)
		{
			if (same(x, y) || same(y, x + n))
			{
				ans++;
				continue;
			}
			else
			{
				unite(x, y + n);
				unite(x + n, y + 2 * n);
				unite(x + 2 * n, y);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}