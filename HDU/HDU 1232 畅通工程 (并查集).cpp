#include <cstdio>
#include <cstring>
#define N 1010
int fa[N], deep[N];
int n, m;
void init(int n)
{
	for (int i = 1; i <= n; i++) fa[i] = i, deep[i] = 0;
}
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
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
int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		init(n);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (fa[i] == i) ans++;
		printf("%d\n", ans - 1);
	}
	return 0;
}