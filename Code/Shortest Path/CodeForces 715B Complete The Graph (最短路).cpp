#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 10;
const int M = 2e4 + 10;

struct Edge
{
	int from, to, next;
    ll w;
	Edge() {}
	Edge(int from, int to, ll w, int next): from(from), to(to), w(w), next(next) {}
} edge[M];
int adj[N], no;

bool flag[M];

void init()
{
    memset(flag, false, sizeof(flag));
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, ll w)
{
    if (w == 0)
    {
        w = INF;
        flag[no] = true;
    }
	edge[no] = Edge(u, v, w, adj[u]);
	adj[u] = no++;
}

ll dis[N];
typedef pair<ll, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis, 0x3f, sizeof(dis));
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
			ll sum = dis[u] + e.w;
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
    int n, m, l, s, t;
    scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
    init();
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        scanf("%d%d%I64d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra(s);
    if (dis[t] < l) return printf("NO\n"), 0;

    for (int i = 0; i < m; i++)
        if (flag[2 * i])
        {
            edge[2 * i].w = edge[2 * i + 1].w = 1;
            dijkstra(s);
            if (dis[t] < l)
            {
                edge[2 * i].w = edge[2 * i + 1].w = l - dis[t] + 1;
            }
        }

    dijkstra(s);
    if (dis[t] != l) return printf("NO\n"), 0;
    printf("YES\n");
    for (int i = 0; i < m; i++)
        printf("%d %d %I64d\n", edge[2 * i].from, edge[2 * i].to, edge[2 * i].w);
    return 0;
}