//CodeForces Gym 101149L Right Build (枚举+最短路)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int M = 2e5 + 10;

struct Edge
{
	int to, w, next;
	Edge() {};
	Edge(int to, int w, int next): to(to), w(w), next(next) {};
} edge1[M], edge2[M];
int adj1[N], no1, adj2[N], no2;

void init1()
{
	memset(adj1, -1, sizeof(adj1));
	no1 = 0;
}
void init2()
{
	memset(adj2, -1, sizeof(adj2));
	no2 = 0;
}
void add1(int u, int v, int w)
{
	edge1[no1] = Edge(v, w, adj1[u]);
	adj1[u] = no1++;
}
void add2(int u, int v, int w)
{
	edge2[no2] = Edge(v, w, adj2[u]);
	adj2[u] = no2++;
}

int dis0[N], dis1[N], dis2[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijkstra1(int start, int dis[], int n)
{
	for (int i = 0; i <= n; i++) dis[i] = INF;
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = adj1[u]; i != -1; i = edge1[i].next)
		{
			Edge &e = edge1[i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

void dijkstra2(int start, int dis[], int n)
{
	for (int i = 0; i <= n; i++) dis[i] = INF;
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = adj2[u]; i != -1; i = edge2[i].next)
		{
			Edge &e = edge2[i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

int main()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	init1(); init2();
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add1(u, v, 1);
		add2(v, u, 1);
	}

	dijkstra1(0, dis0, n);
	dijkstra2(a, dis1, n);
	dijkstra2(b, dis2, n);

	int minx = INF;
	int mini;
	for (int i = 0; i <= n; i++)
	{
		int sum = dis0[i] + dis1[i] + dis2[i];
		if (sum < minx)
		{
			minx = sum;
			mini = i;
		}
	}
	printf("%d\n", minx);
	return 0;
}
