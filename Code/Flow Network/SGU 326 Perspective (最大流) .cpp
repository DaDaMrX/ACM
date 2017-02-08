#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1010;
const int M = 10010;

int n;
int w[25], r[25], m[25][25];

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
		memcpy(cur, head, sizeof(head));
		int f;
		while (f = dfs(s, t, INF)) flow += f;
	}
	return flow;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &m[i][j]);
	w[1] += r[1];

	init();
	int s = 1, p = n + 1;
	int sum = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j < i; j++)
			if (m[i][j] > 0)
			{
				sum += m[i][j];
				add(s, p, m[i][j]);
				add(p, i, INF);
				add(p, j, INF);
				p++;
			}
	int t = p + 1;
	for (int i = 2; i <= n; i++)
	{
		if (w[i] > w[1])
		{
			printf("NO\n");
			return 0;
		}
		add(i, t, w[1] - w[i]);
	}

	if (dinic(s, t) < sum) printf("NO\n");
	else printf("YES\n");
	return 0;
}