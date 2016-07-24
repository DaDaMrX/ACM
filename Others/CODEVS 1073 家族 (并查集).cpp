#include <cstdio>
#include <cstring>
#define N 5010
int fa[N], deep[N];
int n, m, q;
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
	scanf("%d%d%d", &n, &m, &q);
	init(n);
	int a, b;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		unite(a, b);
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &a, &b);
		if (same(a, b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
