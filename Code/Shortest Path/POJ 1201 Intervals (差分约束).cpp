/*
POJ 1201 Intervals (差分约束)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

struct Edge
{
	int to, w, next;
	Edge() {};
	Edge(int to, int w, int next): to(to), w(w), next(next) {};
} edge[M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, int w)
{
	edge[no] = Edge(v, w, adj[u]);
	adj[u] = no++;
}

int dis[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
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
	int n;
	scanf("%d", &n);
	init();
	int minx = INF, maxx = -1;
	while (n--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u - 1, v, -w);
		minx = min(minx, u - 1);
		maxx = max(maxx, v);
	}
	for (int i = minx; i < maxx; i++)
	{
		add(i, i + 1, 0);
		add(i + 1, i, 1);
	}
	dijkstra(minx);
	printf("%d\n", -dis[maxx]);
	return 0;
}
