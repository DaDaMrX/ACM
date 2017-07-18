//Problem A Promotions (DAG图DFS)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 5e3 + 10;
const int M = 2e4 + 10;

struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge1[M], edge2[M];
int adj1[N], no1, adj2[N], no2;

void init1()
{
	memset(adj1, -1, sizeof(adj1));
	no1 = 0;
}
void init2()
{
	memset(adj2, -1, sizeof(adj2));
	no2 = 0;
}
void add1(int u, int v)
{
	edge1[no1] = Edge(v, adj1[u]);
	adj1[u] = no1++;
}
void add2(int u, int v)
{
	edge2[no2] = Edge(v, adj2[u]);
	adj2[u] = no2++;
}

int a, b, n, m;
int down[N], up[N];

bool vis[N];
int dfs1(int u)
{
	vis[u] = true;
	int sum = 1;
	for (int i = adj1[u]; i != -1; i = edge1[i].next)
	{
		Edge& e = edge1[i];
		if (!vis[e.to]) sum += dfs1(e.to);
	}
	return sum;
}
int dfs2(int u)
{
	vis[u] = true;
	int sum = 1;
	for (int i = adj2[u]; i != -1; i = edge2[i].next)
	{
		Edge& e = edge2[i];
		if (!vis[e.to]) sum += dfs2(e.to);
	}
	return sum;
}

int main()
{
	scanf("%d%d%d%d", &a, &b, &n, &m);
	init1(); init2();
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add1(u, v); add2(v, u);
	}

	for (int i = 0; i < n; i++)
	{
		memset(vis, false, sizeof(vis));
		down[i] = dfs1(i);
		memset(vis, false, sizeof(vis));
		up[i] = dfs2(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (n - down[i] < a) ans++;
	printf("%d\n", ans);
	ans = 0;
	for (int i = 0; i < n; i++)
		if (n - down[i] < b) ans++;
	printf("%d\n", ans);
	ans = 0;
	for (int i = 0; i < n; i++)
		if (up[i] - 1 >= b) ans++;
	printf("%d\n", ans);
	return 0;
}
