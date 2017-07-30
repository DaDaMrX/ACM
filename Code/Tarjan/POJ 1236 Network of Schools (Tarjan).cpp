#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e2 + 10;
const int M = 1e4 + 10;

struct Edge
{
	int from, to, next;
	Edge(int from = 0, int to = 0, int next = 0): 
		from(from), to(to), next(next) {};
} edge[M];
int adj[N], no;

void init()
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

int in[N], out[N];

int main()
{
	int n;
	scanf("%d", &n);
	init();
	for (int u = 1, v; u <= n; u++)
		while (scanf("%d", &v), v) add(u, v);
	init_tarjan();
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	if (scc == 1) return printf("1\n0\n"), 0;
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	for (int i = 0; i < no; i++)
		if (belong[edge[i].from] != belong[edge[i].to])
		{
			out[belong[edge[i].from]]++;
			in[belong[edge[i].to]]++;
		}
	int in0 = 0, out0 = 0;
	for (int i = 1; i <= scc; i++)
	{
		if (in[i] == 0) in0++;
		if (out[i] == 0) out0++;
	}
	printf("%d\n%d\n", in0, max(in0, out0));
	return 0;
}
