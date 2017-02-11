/********************************************************************************
求强连通分量
********************************************************************************/
struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(v, adj[u]);
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
void tarjan(int u)
{
	dfn[u] = low[u] = ++index;
	s.push(u); instack[u] = true;
	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v])
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u])
	{
		cnt++;
		int v = -1;
		while (v != u)
		{
			v = s.top(); s.pop();
			instack[v] = false;
			con[v] = cnt;
		}
	}
}

/********************************************************************************
桥
********************************************************************************/
struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;

struct EDGE
{
	int u, v;
	bool bri;
	EDGE() {}
	EDGE(int u, int v, bool bri): u(u), v(v), bri(bri) {};
} e[M];
int bridge;

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

int dfn[N], low[N];
int index, cnt;
stack<int> s;
bool instack[N];
void init_tarjan()
{
	memset(dfn, 0, sizeof(dfn));
	index = cnt = 0;
	while (!s.empty()) s.pop();
	memset(instack, false, sizeof(instack));
	bridge = 0;
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
			//else unite(u, v);
		}
		else if (v != from)
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
}
