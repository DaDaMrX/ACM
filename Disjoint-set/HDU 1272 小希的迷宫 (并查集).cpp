#include <cstdio>
#include <cstring>
#define N 100010
int fa[N], rank[N];
bool flag[N];
void init(int n)
{
	for (int i = 1; i <= n; i++) fa[i] = i, rank[i] = 0;
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
	if (rank[x] < rank[y]) fa[x] = y;
	else
	{
		fa[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
bool connected(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (flag[i] && find(i) == i) sum++;
	if (sum > 1) return false;
	return true;
}
int main()
{
	int a, b;
	int n = N - 2;
	init(n);
	memset(flag, false, sizeof(flag));
	while (scanf("%d%d", &a, &b), ~a)
	{
		if (!a)
		{
			if (connected(n)) printf("Yes\n");
			else printf("No\n");
			init(n);
			memset(flag, false, sizeof(flag));
			continue;
		}
		if (same(a, b))
		{
			printf("No\n");
			while (a) scanf("%d%d", &a, &b);
			init(n);
			memset(flag, false, sizeof(flag));
			continue;
		}
		unite(a, b);
		flag[a] = flag[b] = true;
	}
	return 0;
}