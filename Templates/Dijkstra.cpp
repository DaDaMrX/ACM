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
int n;

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


int dis[N], pre[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
    memset(pre, -1, sizeof(pre));
	dis[start] = 0;
    pre[start] = -1;
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
			if (sum < dis[e.v])
			{
				dis[e.v] = sum;
                pre[e.v] = u;
				pq.push(pii(dis[e.v], e.v));
			}
		}
	}
}

void output_path(int start, int finish)
{
    if (start == finish)
    {
        printf("%s", name[start]);
        return;
    }
    output_path(start, pre[finish]);
    printf("-%s", name[finish]);
}