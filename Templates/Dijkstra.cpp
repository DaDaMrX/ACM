struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
void init(int n)
{
	for (int i = 1; i <= n; i++) vec[i].clear();
}
void add(int u, int v, int w)
{
	vec[u].push_back(Edge(v, w));
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
		for (int i = 0; i < vec[u].size(); i++)
		{
			Edge &e = vec[u][i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}