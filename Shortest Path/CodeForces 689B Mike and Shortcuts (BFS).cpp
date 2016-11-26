/*
CodeForces 689B Mike and Shortcuts (BFS)
边权为1， BFS最短路均可
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;
const int M = 6e5 + 10;

struct Edge
{
	int to, w, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;
void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, int w)
{
	edge[no].to = v;
	edge[no].w = w;
	edge[no].next = adj[u];
	adj[u] = no++;
}
int n, a[N];

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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	init();
	for (int i = 1; i < n; i++) add(i, i + 1, 1), add(i + 1, i, 1);
	for (int i = 1; i <= n; i++) add(i, a[i], 1);

	dijkstra(1);

	for (int i = 1; i < n; i++) printf("%d ", dis[i]);
	printf("%d\n", dis[n]); 
	return 0;
}
