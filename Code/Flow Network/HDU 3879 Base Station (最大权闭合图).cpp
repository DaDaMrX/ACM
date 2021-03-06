﻿/*
HDU 3879 Base Station (最大权闭合图)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 55010;
const int M = 200010;

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
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		init();
		int s = n + m + 2, t = n + m + 1;
		for (int i = 1; i <= n; i++)
		{
			int p;
			scanf("%d", &p);
			add(i, t, p);
		}
		int sum = 0;
		for (int i = n + 1; i <= n + m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(i, a, INF);
			add(i, b, INF);
			add(s, i, c);
			sum += c;
		}
		printf("%d\n", sum - dinic(s, t));
	}
	return 0;
}
