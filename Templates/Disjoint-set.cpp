/*
Disjoint-set
*/
#define N 1010
int fa[N], rank[N];
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