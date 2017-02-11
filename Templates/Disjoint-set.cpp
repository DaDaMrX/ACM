int fa[N], deep[N];
void init()
{	
	memset(fa, -1, sizeof(fa));
	memset(deep, 0, sizeof(deep));
}
int find(int x)
{
	if (fa[x] == -1) return x;
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