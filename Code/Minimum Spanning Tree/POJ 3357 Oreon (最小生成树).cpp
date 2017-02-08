#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 30;
const int M = N * N;
struct Edge
{
	int from, to, w;
	Edge() {};
	Edge(int from, int to, int w) :from(from), to(to), w(w) {};
};
struct Graph
{
	int n, m;
	Edge e[M];
	void set_edge(int n);
	void kruskal();
};
void Graph::set_edge(int n)
{
	this->n = n; this->m = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int w;
			scanf("%d%*c", &w);
			if (j > i && w) e[m++] = Edge(i, j, w);
		}
	}
}
int fa[N], deep[N];
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
	if (e1.w != e2.w) return e1.w < e2.w;
	if (e1.from != e2.from) return e1.from < e2.from;
	return e1.to < e2.to;
}
void Graph::kruskal()
{
	sort(e, e + m, cmp);
	init(n);
	for (int i = 0; i < m; i++)
	{
		if (!same(e[i].from, e[i].to))
		{
			printf("%c-%c %d\n", e[i].from + 'A' - 1, e[i].to + 'A' - 1, e[i].w);
			unite(e[i].from, e[i].to);
		}
	}
}
Graph G;
int main()
{
	int T;
	scanf("%d", &T);
	for (int I = 1; I <= T; I++)
	{
		int n;
		scanf("%d", &n);
		G.set_edge(n);
		printf("Case %d:\n", I);
		G.kruskal();
	}
	return 0;
}