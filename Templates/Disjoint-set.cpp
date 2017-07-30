int fa[N], deep[N], num[N];
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


/*****************************
带统计数量的并查集num[]
下标从1到n，可以任意改
*****************************/

int fa[N], deep[N], num[N];
void init(int n)
{	
	memset(fa, -1, sizeof(fa));
	memset(deep, 0, sizeof(deep));
	for (int i = 1; i <= n; i++) num[i] = 1;
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
bool same(int x, int y)
{
	return find(x) == find(y);
}