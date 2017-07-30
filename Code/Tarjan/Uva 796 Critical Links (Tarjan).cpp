#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 2e4 + 10;

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

typedef pair<int, int> pii;
pii e[M];
int sum;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		init();
		for (int i = 0; i < n; i++)
		{
			int u, s, v;
			scanf("%d (%d)", &u, &s);
			while (s--) scanf("%d", &v), add(u, v), add(v, u);
		}
		init_tarjan();
		for (int i = 0; i < n; i++)
		{
			if (dfn[i]) continue;
			tarjan(i, i);
		}
		printf("%d critical links\n", numBridge);
		sum = 0;
		for (int i = 0; i < no / 2; i++)
			if (bridge[2 * i]) 
			{
				e[sum] = pii(edge[2 * i].from, edge[2 * i].to);
				if (e[sum].first > e[sum].second) swap(e[sum].first, e[sum].second);
				sum++;
			}
		sort(e, e + sum);
		for (int i = 0; i < sum; i++) printf("%d - %d\n", e[i].first, e[i].second);
		printf("\n");
	}
	return 0;
}
