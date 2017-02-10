//Problem H Robot Challenge (最短路)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = N * N;

struct Edge
{
	int to, next;
    double w;
	Edge() {};
	Edge(int to, double w, int next): to(to), w(w), next(next) {};
} edge[M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, double w)
{
	edge[no] = Edge(v, w, adj[u]);
	adj[u] = no++;
}

int n;
struct Point
{
    int x, y;
} p[N];
int a[N], sum[N];

double dis[N];
typedef pair<double, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
    for (int i = 0; i <= n; i++) dis[i] = INF;
	dis[start] = 0.0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0.0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
			double sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

double dist(Point p1, Point p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    while (scanf("%d", &n), n)
    {
        p[0].x = p[0].y = 0.0; 
        a[0] = 0; sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &p[i].x, &p[i].y, a + i);
            sum[i] = sum[i - 1] + a[i];
        }
        p[n + 1].x = p[n + 1].y = 100.0;
        a[n + 1] = 0;

        init();
        for (int i = 0; i <= n; i++)
            for (int j = i + 1; j <= n + 1; j++)
                add(i, j, dist(p[i], p[j]) + sum[j - 1] - sum[i] + 1);
        
        n++;
        dijkstra(0);

        printf("%.3f\n", dis[n]);
    }
    return 0;
}
