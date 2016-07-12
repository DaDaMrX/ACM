#include <cstdio>
#include <cstring>
#define N 30010
int fa[N], deep[N], num[N];
int n, m;
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		fa[i] = i;
		deep[i] = 0;
		num[i] = 1;
	}
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
	if (deep[x] < deep[y])
	{
		fa[x] = y;
		num[y] += num[x];
	}
	else
	{
		fa[y] = x;
		num[x] += num[y];
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
			int k, a, b;
			scanf("%d%d", &k, &a);
			for (int i = 2; i <= k; i++)
			{
				scanf("%d", &b);
				unite(a, b);
			}
		}
		printf("%d\n", num[fa[0]]);
	}
	return 0;
}