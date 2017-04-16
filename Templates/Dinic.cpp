最大流Dinic算法。
输入：建图，结点数n，边数m，每条边的起点u，终点v，容量c。参数，源点s，汇点t。
输出：最大流。
条件：有向图网络以邻接表存储，节点编号及源汇点编号没有限制。
思想：每次BFS在当前残余网络上建立层次图，然后在层次图上多次DFS寻找增广路增大流量。多次DFS中用cur[]数组进行当前弧优化，即对已经确定没有增广路的分支不再进入递归。

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

struct Edge
{
	int to, c, next;
	Edge() {};
	Edge(int to, int c, int next) : to(to), c(c), next(next) {};
} edge[2 * M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}

void add(int u, int v, int c)
{
	edge[no] = Edge(v, c, adj[u]);
	adj[u] = no++;
	edge[no] = Edge(u, 0, adj[v]);
	adj[v] = no++;
}

queue<int> q;
int level[N];
bool bfs(int s, int t)
{
	while (!q.empty()) q.pop();
	memset(level, -1, sizeof(level));
	level[s] = 0; q.push(s);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
			if (e.c && level[e.to] == -1)
			{
				level[e.to] = level[u] + 1;
				if (e.to == t) return true;
				q.push(e.to);
			}
		}
	}
	return false;
}

int cur[N];
int dfs(int u, int t, int flow)
{
	if (u == t) return flow;
	for (int &i = cur[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.c && level[e.to] > level[u])
		{
			int f = dfs(e.to, t, min(flow, e.c));
			if (f)
			{
				e.c -= f;
				edge[i ^ 1].c += f;
				return f;
			}
		}
	}
	return 0;
}

int dinic(int s, int t)
{
	int flow = 0;
	while (bfs(s, t))
	{
		memcpy(cur, adj, sizeof(adj));
        int f; int c = 0;
		while (f = dfs(s, t, INF)) flow += f;
	}
	return flow;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init();
    while (m--)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
    }
    int ans = dinic(0, n - 1);
    printf("%d\n", ans);
	return 0;
}

Input
6 9
0 1 10
0 2 10
1 2 2
1 3 4
1 4 8
2 4 9
3 5 10
4 3 6
4 5 10

Output
19