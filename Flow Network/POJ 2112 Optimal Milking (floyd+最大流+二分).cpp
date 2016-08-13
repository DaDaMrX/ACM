/*
POJ 2112 Optimal Milking (floyd+最大流+二分)
首先用Floyd跑出k+c个点之间的最短路，然后二分挤奶机与奶牛之间的最大距离mid，
取map[i][j]<=mid的边建图，容量为1，添加源点，与每台挤奶机之间边的容量为m，
添加汇点，每头奶牛与汇点之间边的容量为1，跑dinic最大流，
若满流，则减小最大距离，反之，增加最大距离
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 250;
const int M = 8000;

int k, c, m, n;
int map[N][N];

void floyd(int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
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

void build(int d)
{
	init();
	for (int i = 1; i <= k; i++)
		for (int j = k + 1; j <= n; j++)
			if (map[i][j] <= d) add(i, j, 1);
	for (int i = 1; i <= k; i++) add(0, i, m);
	for (int j = k + 1; j <= n; j++) add(j, n + 1, 1);
}

int main()
{
	scanf("%d%d%d", &k, &c, &m);
	n = k + c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
			if (i != j && !map[i][j]) map[i][j] = INF;
		}

	floyd(n);

	int left = 0, right = 0;
	for (int i = 1; i <= k; i++)
		for (int j = k + 1; j <= n; j++)
			right = max(right, map[i][j]);

	while (left < right - 1)
	{
		int mid = left + (right - left >> 1);
		build(mid);
		if (dinic(0, n + 1) == c) right = mid;
		else left = mid;
	}

	printf("%d\n", right);
	return 0;
}