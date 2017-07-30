/***********************************************************************************
Tarjan算法求有向图中的强连通分量 O(n+m)
1. 强连通图：任意两点均有边可达的有向图
2. 输入：n个点m条边的有向图，编号任意
3. 输出：scc：强连通分量的数量
   belong[u]：结点u所属的强连通分量编号，编号从1到n
   num[i]: 第i个连通分量所含的节点数，可根据需要添加
4. 原理：dfn[u]为结点u的dfs序编号
   low[u]为结点u可到达的最小的dfs序编号
   当low[u]<dfn[u]时，说明从u点可以到达更靠前的点，u不是搜索树中强连通分量的树根
   当low[u]=dfn[u]时，说明从u点不能到达更靠前的点，u是搜索树中强连通分量的树根
***********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

struct Edge
{
	int to, next;
	Edge(int to = 0, int next = 0): to(to), next(next) {};
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
    scanf("%d%d", &n, &m);
    init();
    int u, v;
    while (m--) scanf("%d%d", &u, &v), add(u, v);
    init_tarjan();
    tarjan(1);
    for (int i = 1; i <= n; i++) printf("%d ", belong[i]);
    printf("\n");
    for (int i = 1; i <= scc; i++) printf("%d ", num[i]);
    printf("\n");
    return 0;
}

/**********
Input
6 8
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6

Output
3 3 3 3 2 1 
1 1 4

**********/

/**************************************************************************
Tarjan算法求无向图中的桥和割点
1. 输入：n个点m条边的有向图，编号任意
2. 输出：numBridge：桥的数量
		bridge[i]: 边i是否为桥
		numCut: 割点的数量
		cut[i]：点i是否为割点
		addblock[i]：删除i点后增加的连通块的数量
3. 原理：dfn[u]为结点u的dfs序编号
   low[u]为结点u可到达的最小的dfs序编号
   当low[v]> dfn[u]时，说明从u点不能到达u以及u之前的点，(u,v)是桥
   当low[v]>=dfn[u]时，说明从u点不能到达u之前的点，u是割点，v属于u分割的一个连通块
   根节点特判
***************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

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

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}

	init_tarjan();
	tarjan(1, 1);

	printf("numBridge = %d\n", numBridge);
	printf("Briges: ");
	for (int i = 0; i < m; i++)
		if (bridge[2 * i]) printf("(%d,%d) ", edge[2 * i].from, edge[2 * i].to);
	printf("\n");

	printf("numCut = %d\n", numCut);
	printf("Cuts: ");
	for (int i = 1; i <= n; i++)
		if (cut[i]) printf("%d ", i);
	printf("\n");
	printf("addblock: ");
	for (int i = 1; i <= n; i++)
		if (cut[i]) printf("%d ", addblock[i]);
	printf("\n");
	return 0;
}


/*********************
GRAPH
1       4
| \   /
|   3
| /   \
2       5

INPUT
5 5
1 2  1 3  2 3
3 4  3 5

OUTPUT
numBridge = 2
Briges: (3,4) (3,5) 
numCut = 1
Cuts: 3 
addblock: 2

*********************/
