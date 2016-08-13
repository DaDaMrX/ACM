#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
const int M = 2e4 + 10;
struct Edge
{
	int a, b, w;
	Edge() {};
	Edge(int a, int b, int w) : a(a), b(b), w(w) {};
} e[M];
int fa[N], deep[N];
int n, m;
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
bool cmp(Edge e1, Edge e2)
{
	return e1.w > e2.w;
}
int kruskal()
{
	sort(e, e + m, cmp);
	init(n);
	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++)
		if (!same(e[i].a, e[i].b))
		{
			unite(e[i].a, e[i].b);
			ans += e[i].w;
			cnt++;
			if (cnt == n - 1) break;
		}
	if (cnt < n - 1) return -1;
	return ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		e[i] = Edge(a, b, w);
	}
	printf("%d\n", kruskal());
	return 0;
}