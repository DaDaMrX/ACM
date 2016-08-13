/*
POJ 3281 Dining (最大流)
1.因为是牛选择食物和饮料，故将牛放在中间，食物和饮料放两边
2.每头牛只能选则一种食物和饮料，即点有容量限制，故拆点，容量为1
3.每中食物和饮料只能选一次，故在牛和食物之间，牛和饮料之间，
以及源点和食物之间，饮料和汇点之间，建立容量为1的边
3.这样此网络的最大流即为最多能满足的牛的数量
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 500;
const int M = 11000;

int n, fd, dk, sum;

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

void build(int s, int t)
{
	for (int i = 1; i <= fd; i++) add(s, i, 1);
	for (int i = fd + 1; i <= fd + n; i++) add(i, i + n, 1);
	for (int i = fd + 2 * n + 1; i <= sum; i++) add(i, t, 1);
	for (int i = 1; i <= n; i++)
	{
		int food, drink;
		scanf("%d%d", &food, &drink);
		while (food--)
		{
			int ff;
			scanf("%d", &ff);
			add(ff, fd + i, 1);
		}
		while (drink--)
		{
			int dd;
			scanf("%d", &dd);
			add(fd + n + i, fd + 2 * n + dd, 1);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &fd, &dk);
	sum = fd + 2 * n + dk;
	init();
	int s = 0, t = sum + 1;
	build(s, t);
	printf("%d\n", dinic(s, t));
	return 0;
}