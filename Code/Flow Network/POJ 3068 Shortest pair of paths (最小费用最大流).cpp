/*
POJ 3068 "Shortest" pair of paths (最小费用最大流)
1.建图，两条路径不能有公共点，即点有容量限制，拆点，容量为1花费为0
2.亦不能有公共边，故每条边容量为1， 花费为题目所给。
3.因要找两条路，故源点0和汇点n-1的容量为2
4.跑一边最小费用最大流，先判断是否满流，即最大流是否为2，若满流，输出最小花费
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 150;
const int M = 3e4;

int head[N], d[N], s, t, no, dis[N][N], vis[N], pre[N];
struct Edge
{
	int u, v, flow, next, cost;
	Edge() {};
	Edge(int x, int y, int z, int w, int c) :u(x), v(y), next(z), flow(w), cost(c) {};
} edge[M];
void add(int x, int y, int z, int c)
{
	edge[no] = Edge(x, y, head[x], z, c);	head[x] = no++;
	edge[no] = Edge(y, x, head[y], 0, -c); head[y] = no++;
}
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
queue<int>q;
bool spfa()
{
	int x, y;
	while (!q.empty()) q.pop();
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	d[s] = 0; vis[s] = true; q.push(s);
	while (!q.empty()) 
	{
		x = q.front(); q.pop(); vis[x] = false;
		for (int i = head[x]; i != -1; i = edge[i].next) 
		{
			if (edge[i].flow && d[y = edge[i].v] > d[x] + edge[i].cost)
			{
				d[y] = d[x] + edge[i].cost; pre[y] = i;
				if (vis[y]) continue;
				vis[y] = true; q.push(y);
			}
		}
	}
	return d[t] != d[t + 1];
}
int mcmf(int &flow)
{
	int mincost = 0, maxflow = 0, minflow, i;
	while (spfa()) {
		minflow = INF;
		for (i = pre[t]; i != -1; i = pre[edge[i].u])
			minflow = min(minflow, edge[i].flow);
		for (i = pre[t]; i != -1; i = pre[edge[i].u]) {
			edge[i].flow -= minflow;
			edge[i ^ 1].flow += minflow;
		}
		mincost += d[t] * minflow; maxflow += minflow;
	}
	flow = maxflow;
	return mincost;
}

int main()
{
	int n, m, cas = 0;
	while (scanf("%d%d", &n, &m), n)
	{
		init();
		s = 0; t = n + n - 1;
		add(0, n, 2, 0);
		for (int i = 1; i <= n - 2; i++) add(i, n + i, 1, 0);
		add(n - 1, n + n - 1, 2, 0);

		while (m--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(n + a, b, 1, c);
		}

		int flow;
		int ans = mcmf(flow);
		printf("Instance #%d: ", ++cas);
		if (flow < 2) printf("Not possible\n");
		else printf("%d\n", ans);
	}
	return 0;
}