/*
POJ 2987 Firing (最大权闭合图)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 5e3 + 10;
const int M = 7e4 + 10;

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
int dfs(int u, int t, ll flow)
{
	if (u == t) return flow;
	for (int i = cur[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.c && level[e.to] > level[u])
		{
			ll f = dfs(e.to, t, min(flow, (ll)e.c));
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
ll dinic(int s, int t)
{
	ll flow = 0;
	while (bfs(s, t))
	{
		for (int i = s; i <= t; i++) cur[i] = head[i];
		ll f;
		while (f = dfs(s, t, INF)) flow += f;
	}
	return flow;
}

bool vis[N];
int cnt = 0;
void dfs_ans(int u)
{
	vis[u] = true;
	cnt++;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.c && !vis[e.to]) dfs_ans(e.to);
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	init();
	int s = 0, t = n + 1;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int c;
		scanf("%d", &c);
		if (c > 0)
		{
			add(s, i, c);
			sum += c;
		}
		else
		{
			add(i, t, -c);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b, INF);
	}
	ll ans = sum - dinic(s, t);

	memset(vis, false, sizeof(vis));
	dfs_ans(s);
	cnt--;

	printf("%d %lld\n", cnt, ans);
	return 0;
}