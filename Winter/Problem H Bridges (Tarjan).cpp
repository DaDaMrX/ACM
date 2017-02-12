// Problem H Bridges (Tarjan)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int fa[N], deep[N];
void init_set(int n)
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

struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;
int bridge;

struct EDGE
{
	int u, v;
	bool bri;
	EDGE() {}
	EDGE(int u, int v, bool bri): u(u), v(v), bri(bri) {};
} e[M];

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(v, adj[u]);
	e[no] = EDGE(u, v, false);
	adj[u] = no++;
}

int dfn[N], low[N], con[N];
int index, cnt;
stack<int> s;
bool instack[N];
void init_tarjan()
{
	memset(dfn, 0, sizeof(dfn));
	index = cnt = 0;
	while (!s.empty()) s.pop();
	memset(instack, false, sizeof(instack));
}
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++index;
	s.push(u); instack[u] = true;
	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (!dfn[v])
		{
			tarjan(v, u);
			low[u] = min(low[u], low[v]);

			if (low[v] > dfn[u])
			{
				e[i].bri = true;
				e[i ^ 1].bri = true;
				bridge++;
			}
			else unite(u, v);
		}
		else if (v != from)
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
}

queue<int> q;
int step[N];
int bfs(int start, int& finish)
{
	while (!q.empty()) q.pop();
	memset(step, -1, sizeof(step));
	q.push(start);
	step[start] = 0;

	int u;
	while (!q.empty())
	{
		u = q.front(); q.pop();
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (step[v] != -1) continue;
			q.push(v);
			step[v] = step[u] + 1;
		}
	}

	finish = u;
	return step[u];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i <= m; i++)
{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v); 
			add(v, u);
		}
		
		bridge = 0;
		init_set(n);
		init_tarjan();
		tarjan(1, -1);

		if (bridge == 0)
		{
			printf("0\n");
			continue;
		}

		init();
		int start;
		for (int i = 0; i < 2 * m; i++)
			if (e[i].bri)
			{
				int u = find(e[i].u);
				int v = find(e[i].v);
				add(u, v);
				add(v, u);
				start = u;
			}

		int end1;
		bfs(start, end1);
		int d = bfs(end1, start);

		printf("%d\n", bridge - d);
	}
	return 0;
}
