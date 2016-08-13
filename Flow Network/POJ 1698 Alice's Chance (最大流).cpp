/*
POJ 1698 Alice's Chance (最大流)
1.这种多任务，多方案，有重叠的调度问题，要想到用网络流来解决
2.在源点与每一部电影之间建边，容量为每一部电影需要的演出天数
3.对与每一部电影，与其可以演出的日期连边，容量为1
3.在所有的日期与汇点之间建边，容量为1（实际只用到有演出的日期）
4.网络流问题，每一条有向边要用两个结构体来存，数组开小会T
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 410;
const int M = 2e4 + 10;

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

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		s = 0; t = N - 1;
		int n;
		scanf("%d", &n);
		int sum_day = 0, max_week = 0;
		for (int i = 1; i <= n; i++)
		{
			int act[8];
			for (int j = 1; j <= 7; j++) scanf("%d", &act[j]);
			int day, week;
			scanf("%d%d", &day, &week);
			sum_day += day; 
			max_week = max(max_week, week);
			add(s, i, day);
			for (int j = 1; j <= 7; j++)
				if (act[j])
					for (int k = 0; k < week; k++)
						add(i, n + k * 7 + j, 1);
		}
		for (int j = n + 1; j <= n + max_week * 7; j++) add(j, t, 1);
		if (dinic() == sum_day) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}