#include <cstdio>
#include <cstring>
#include <cmath>
#define N 1010
struct point
{
	int x, y;
} computer[N];
bool map[N][N], usable[N];
int fa[N], rank[N];
int n, d;
double distance(point a, point b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
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
int main()
{
	scanf("%d%d", &n, &d);
	memset(map, false, sizeof(map));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &computer[i].x, &computer[i].y);
		for (int j = 1; j < i; j++)
			if (distance(computer[i], computer[j]) <= d) map[i][j] = map[j][i] = true;
	}
	getchar();
	memset(usable, false, sizeof(usable));
	init(n);
	char c;
	while (~(c = getchar()))
	{
		if (c == 'O')
		{
			int p;
			scanf("%d%*c", &p);
			usable[p] = true;
			for (int i = 1; i <= n; i++)
				if (map[p][i] && usable[i]) unite(p, i);
		}
		if (c == 'S')
		{
			int p, q;
			scanf("%d%d%*c", &p, &q);
			if (same(p, q)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}