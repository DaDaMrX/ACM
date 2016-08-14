/*
HDU 4183 Pahom on Water (最大流)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const int N = 610;
const int M = 2e5;

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

struct Pad
{
	double f;
	int x, y, r;
} p[310];

bool adj(Pad p1, Pad p2)
{
	int dx = p1.x - p2.x, dy = p1.y - p2.y, R = p1.r + p2.r;
	return dx * dx + dy * dy < R * R;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		init();
		int s = 0, t = 2 * n + 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%d%d%d", &p[i].f, &p[i].x, &p[i].y, &p[i].r);

			if (abs(p[i].f - 400.0) < eps)
			{
				add(s, i, 2);
				add(i, n + i, 2);

			}
			else if (abs(p[i].f - 789.0) < eps)
			{
				add(n + i, t, 2);
				add(i, n + i, 2);
			}
			else add(i, n + i, 1);

			for (int j = 1; j < i; j++)
				if (adj(p[i], p[j]))
				{
					if (p[i].f < p[j].f) add(n + i, j, 1);
					else add(n + j, i, 1);
				}
		}
		if (dinic(s, t) == 2) printf("Game is VALID\n");
		else printf("Game is NOT VALID\n");
	}
	return 0;
}