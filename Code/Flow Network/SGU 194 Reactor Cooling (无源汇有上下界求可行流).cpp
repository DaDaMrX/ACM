/*
SGU 194 Reactor Cooling (无源汇有上下界求可行流)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 20000;
const int M = 1000000;

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

int du[N], down[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	int s = 0, t = n + 1;
	memset(du, 0, sizeof(du));
	for (int i = 0; i < m; i++)
	{
		int u, v, b, c;
		scanf("%d%d%d%d", &u, &v, &b, &c);
		add(u, v, c - b);
		du[u] -= b;
		du[v] += b;
		down[i] = b;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (du[i] > 0)
		{
			add(s, i, du[i]);
			sum += du[i];
		}
		else if (du[i] < 0) add(i, t, -du[i]);
	}

	if (dinic(s, t) < sum)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < m; i++) printf("%d\n", down[i] + edge[2 * i + 1].c);
	return 0;
}