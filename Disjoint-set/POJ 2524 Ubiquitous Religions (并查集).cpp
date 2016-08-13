#include <cstdio>
#include <cstring>
#define N 50010
int fa[N], deep[N];
int n, m, sum;
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
	int cnt = 0;
	while (scanf("%d%d", &n, &m), n)
	{
		cnt++;
		init(n);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
		sum = 0;
		for (int i = 1; i <= n; i++)
			if (fa[i] == i) sum++;
		printf("Case %d: %d\n", cnt, sum);
	}
	return 0;
}