/*
HDU 5294 Tricks Device (最短路+最小割)
1.最短路可能不止一条，不同的最短路可能共用某些边，首先需找出参与构建最短路的边
2.找最短路：无向图，从起点和终点各跑一遍最短路，然后枚举每条边(u,v)，
若从起到到u的距离+(u,v)边的距离+终点到v的距离=最短距离，说明这条边在最短路上
3.对最短路上的每条边，建立容量为1的网络流的边，此时最小割就是破坏最短路所需的最少边
4.要求最多可以破坏多少条边而仍然有最短路存在，只需找出边最少的最短路径，总边数m-最短路径的最少边即为所求
5.在原图中，对于参与最短路的边，将其花费改为1，其余的边花费修改为INF，此时再跑一遍最短路
起点到终点的最短距离即为所需的最少边数。修改边的花费可在枚举边的时候一并完成
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e3 + 10;
const int M = 6e4 + 10;

struct Edge1
{
	int to, w;
	Edge1() {};
	Edge1(int to, int w) : to(to), w(w) {};
};
vector<Edge1> vec[N];
int dis1[N], dis2[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start, int dis[], int n)
{
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = 0; i < vec[u].size(); i++)
		{
			Edge1 &e = vec[u][i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

struct Edge
{
	int to, c, next;
	Edge() {};
	Edge(int to, int c, int next) : to(to), c(c), next(next) {};
} edge[2 * M];
int head[N], no;
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int u, int v, int c)
{
	edge[no] = Edge(v, c, head[u]);
	head[u] = no++;
	edge[no] = Edge(u, 0, head[v]);
	head[v] = no++;
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
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
			if (e.c && level[e.to] < 0)
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
	for (int i = cur[u]; i != -1; i = edge[i].next)
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
		for (int i = s; i <= t; i++) cur[i] = head[i];
		int f;
		while (f = dfs(s, t, INF)) flow += f;
	}
	return flow;
}

int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= n; i++) vec[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			vec[a].push_back(Edge1(b, c));
			vec[b].push_back(Edge1(a, c));
		}
		dijkstra(1, dis1, n);
		dijkstra(n, dis2, n);
		int shortest = dis1[n];

		init();
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < vec[i].size(); j++)
			{
				Edge1 &e = vec[i][j];
				if (dis1[i] + e.w + dis2[e.to] == shortest)
				{
					add(i, e.to, 1);
					e.w = 1;
				}
				else e.w = INF;
			}
		printf("%d ", dinic(1, n));

		dijkstra(1, dis1, n);
		printf("%d\n", m - dis1[n]);
	}
	return 0;
}