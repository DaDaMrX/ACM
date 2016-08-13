/*
POJ 3204 Ikki's Story I - Road Reconstruction (最大流割边)
1.单纯统计剩余容量为0的每条边并不能得到正确答案，因为一条路上可能有多条边达到最大容量，
只增加期中一条边的容量并不能形成增广路
2.所求边应该满足这样的条件，存在一条经过它的从源点到汇点的路径，
此路径上除去这条边以外每条边均有剩余容量
3.说明只是这条边限制了这条路径的流量，扩大这条边的容量，总流量就会增加
4.故在参与网络上从源点做一次dfs，能到达的点标记为1，然后选择残余网络上正向弧剩余容量不为0的边反向建图，
从汇点再做一次dfs，能到达的点标记为2。
5.遍历每条边，若起点被标记为1，终点被标记为2，则统计这条边。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 510;
const int M = 2 * 5010;

int head[N], cur[N], dis[N], st[M], s, t, no;
struct Node
{
	int u, v, flow, next;
	Node() {};
	Node(int x, int y, int z, int w) : u(x), v(y), next(z), flow(w) {};
} p[M];
void add(int x, int y, int z)
{
	p[no] = Node(x, y, head[x], z); head[x] = no++;
	p[no] = Node(y, x, head[y], 0); head[y] = no++;
}
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
queue<int>q;
bool bfs()
{
	int i, x, y;
	while (!q.empty()) q.pop();
	memset(dis, -1, sizeof(dis));
	dis[s] = 0; q.push(s);
	while (!q.empty())
	{
		x = q.front();	q.pop();
		for (i = head[x]; i != -1; i = p[i].next)
		{
			if (p[i].flow && dis[y = p[i].v] < 0)
			{
				dis[y] = dis[x] + 1;
				if (y == t)	return true;
				q.push(y);
			}
		}
	}
	return false;
}
int dinic()
{
	int i, loc, top, x = s, nowflow, maxflow = 0;
	while (bfs())
	{
		for (i = s; i <= t; i++)	cur[i] = head[i];
		top = 0;
		while (true)
		{
			if (x == t)
			{
				nowflow = INF;
				for (i = 0; i < top; i++)
				{
					if (nowflow > p[st[i]].flow)
					{
						nowflow = p[st[i]].flow;
						loc = i;
					}
				}
				for (i = 0; i < top; i++)
				{
					p[st[i]].flow -= nowflow;
					p[st[i] ^ 1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc;	x = p[st[top]].u;
			}
			for (i = cur[x]; i != -1; i = p[i].next)
				if (p[i].flow && dis[p[i].v] == dis[x] + 1) break;
			cur[x] = i;
			if (i != -1)
			{
				st[top++] = i;
				x = p[i].v;
			}
			else
			{
				if (!top) break;
				dis[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	return maxflow;
}

struct point
{
	int u, v, next;
	point() {};
	point(int u, int v, int next) : u(u), v(v), next(next) {};
} p2[M];
int head2[N], no2;

int n, m;
int flag[N];
bool vis[N];

void dfs1(int u)
{
	vis[u] = true;
	flag[u] = 1;
	for (int i = head[u]; i != -1; i = p[i].next)
		if (p[i].flow && !vis[p[i].v]) dfs1(p[i].v);
}

void init2()
{
	memset(head2, -1, sizeof(head2));
	no2 = 0;
}
void add2(int u, int v)
{
	p2[no2] = point(u, v, head2[u]);
	head2[u] = no2++;
}
void build2()
{
	for (int i = 0; i < m; i++)
		if (p[2 * i].flow)
			add2(p[2 * i].v, p[2 * i].u);
}
void dfs2(int u)
{
	vis[u] = true;
	flag[u] = 2;
	for (int i = head2[u]; i != -1; i = p2[i].next)
		if (!vis[p2[i].v]) dfs2(p2[i].v);
}

int main()
{
	scanf("%d%d", &n, &m);
	init();
	s = 0; t = n - 1;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	dinic();

	memset(vis, false, sizeof(vis));
	dfs1(s);

	init2();
	build2();
	memset(vis, false, sizeof(vis));
	dfs2(t);

	int ans = 0;
	for (int i = 0; i < m; i++)
		if (flag[p[2 * i].u] == 1 && flag[p[2 * i].v] == 2)
			ans++;

	printf("%d\n", ans);
	return 0;
}