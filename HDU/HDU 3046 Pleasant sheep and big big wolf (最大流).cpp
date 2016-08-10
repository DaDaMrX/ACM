/*
HDU 3046 Pleasant sheep and big big wolf (最大流)
将该N*M的矩阵看做N*M个点，若两格有公共边就连一条容量为1的无向边。
源点向每只羊连边，每只狼向汇点连边，容量均为无穷大。
该图的最小割即为最短篱笆的总长
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 4e4 + 10;
const int M = 5 * N;

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

struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};
typedef Point Vector;
Point operator+(Point A, Vector V)
{
	return Point(A.x + V.x, A.y + V.y);
}
Vector dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int n, m;

bool valid(Point P)
{
	return P.x >= 1 && P.x <= n && P.y >= 1 && P.y <= m;
}
int index(Point P)
{
	return (P.x - 1) * m + P.y;
}
void deal(int i, int j, int a)
{
	Point from(i, j);
	for (int k = 0; k < 4; k++)
	{
		Point to = from + dir[k];
		if (!valid(to)) continue;
		add(index(from), index(to), 1);
	}
	if (a == 1) add(s, index(from), INF);
	else if (a == 2) add(index(from), t, INF);
}
int main()
{
	int cas = 0;
	while (~scanf("%d%d", &n, &m))
	{
		init();
		s = 0; t = n * m + 1;
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				int a;
				scanf("%d", &a);
				deal(i, j, a);
			}
		printf("Case %d:\n", ++cas);
		printf("%d\n", dinic());
	}
	return 0;
}