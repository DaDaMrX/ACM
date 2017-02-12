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
	int from, to, next;
	bool flag;
	Edge() {};
	Edge(int from, int to, bool flag, int next): 
		from(from), to(to), flag(flag), next(next) {};
} edge[M];
int adj[N], no;
int bridge;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(u, v, false, adj[u]);
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
				edge[i].flag = true;
				edge[i ^ 1].flag = true;
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
