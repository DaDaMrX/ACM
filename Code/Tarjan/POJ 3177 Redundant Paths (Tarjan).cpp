#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e3 + 10;
const int M = 2e4 + 10;

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

struct Edge
{
	int from, to, next;
	Edge(int from = 0, int to = 0, int next = 0): 
		from(from), to(to), next(next) {};
} edge[M];
int adj[N], no;
void init_graph()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(u, v, adj[u]);
	adj[u] = no++;
}

int dfn[N], low[N], cnt;
int numBridge;
bool bridge[M];
int numCut, addblock[N];
bool cut[N];
void init_tarjan()
{
	memset(dfn, 0, sizeof(dfn));
	cnt = 0;
	memset(bridge, false, sizeof(bridge));
    numBridge = 0;
    memset(cut, false, sizeof(cut));
    memset(addblock, 0, sizeof(addblock));
    numCut = 0;
}
void tarjan(int u, int f)
{
	dfn[u] = low[u] = ++cnt;
    int son = 0;
	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
        if (v == f) continue;
		if (dfn[v]) 
		{
			low[u] = min(low[u], dfn[v]);
			continue;
		}
		son++;
		tarjan(v, u);
		low[u] = min(low[u], low[v]);
		if (low[v] > dfn[u]) // (u,v) is a bridge
		{
			numBridge++;
			bridge[i] = bridge[i ^ 1] = true;
		}
		else unite(u, v);
		if(u != f && low[v] >= dfn[u]) // u is a cut point
		{
			cut[u] = true;
			addblock[u]++;
		}
	}
	if (u == f && son > 1) // su is the root and a cut point
	{
		cut[u] = true;
		addblock[u] = son - 1;
	}
	if (cut[u]) numCut++;
}

int deg[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init(); init_graph();
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	init();
	init_tarjan();
	tarjan(1, 1);
	memset(deg, 0, sizeof(deg));
	for (int i = 0; i < m; i++)
		if (bridge[2 * i])
		{
			int u = find(edge[2 * i].from);
			int v = find(edge[2 * i].to);
			deg[u]++; deg[v]++;
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1) ans++;
	printf("%d\n", (ans + 1) / 2);
	return 0;
}
