#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 10;
const int M = 1e5 + 10;

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

int dfn[N], low[N], cnt;
int st[N], top;
bool instack[N];
int scc, belong[N], num[N];
void init_tarjan()
{
	memset(dfn, 0, sizeof(dfn));
	cnt = top = scc = 0;
	memset(instack, false, sizeof(instack));
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++cnt;
    st[top++] = u; instack[u] = true;
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
		num[++scc] = 0; 
		int v = -1;
		while (v != u)
		{
            v = st[--top]; instack[v] = false;
			belong[v] = scc; num[scc]++;
		}
	}
}


int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n)
	{
		init();
		int u, v;
		while (m--) scanf("%d%d", &u, &v), add(u, v);
		init_tarjan();
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) tarjan(i);
		printf("%s\n", scc == 1 ? "Yes" : "No");
	}
	return 0;
}
