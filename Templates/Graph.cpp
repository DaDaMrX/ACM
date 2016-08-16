//graph-head
struct Edge
{
	int to, next;
} edge[2 * N];
int head[N], no;
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int u, int v)
{
	edge[no].to = v; 
	edge[no].next = head[u];
	head[u] = no++;
}

//graph-head-weight
struct Edge
{
	int to, w, next;
} edge[2 * N];
int head[N], no;
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
void add(int u, int v, int w)
{
	edge[no].to = v;
	edge[no].w = w;
	edge[no].next = head[u];
	head[u] = no++;
}

//graph-vec-weight
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int n, m;

scanf("%d%d", &n, &m);
for (int i = 1; i <= n; i++) vec[i].clear();
for (int i = 1; i <= m; i++)
{
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w);
	vec[a].push_back(Edge(b, w));
	vec[b].push_back(Edge(a, w));
}

//graph-map
int map[N][N]
int n, m;

scanf("%d%d", &n, &m);
memset(map, 0x7f, sizeof(map));
for (int i = 1; i <= m; i++)
{
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w);
	if (w < map[a][b]) map[a][b] = map[b][a] = w;
}

//dijkstra-priority_queue-vec
#include <queue>
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int n, m;

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
		for (int j = 0; j < vec[u].size(); j++)
		{
			Edge e = vec[u][j];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

//dijkstra-map
int map[N][N], dis[N];
bool vis[N];
int n, m;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		int mini = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (mini == -1 || dis[j] < dis[mini])) mini = j;
		vis[mini] = true;
		for (int j = 1; j <= n; j++)
			if (map[mini][j] < INF)
				dis[j] = min(dis[j], dis[mini] + map[mini][j]);
	}
}

//dijkstra-priority_queue-vec-second shortest path
#include <queue>
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int n, m;

int dis1[N], dis2[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis1, 0x7f, sizeof(dis1));
	memset(dis2, 0x7f, sizeof(dis2));
	dis1[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second, d = p.first;
		if (dis2[u] < d) continue;
		for (int j = 0; j < vec[u].size(); j++)
		{
			Edge e = vec[u][j];
			int sum = d + e.w;
			if (sum < dis1[e.to])
			{
				dis2[e.to] = dis1[e.to];
				dis1[e.to] = sum;
				pq.push(pii(dis1[e.to], e.to));
				pq.push(pii(dis2[e.to], e.to));
			}
			else if (sum > dis1[e.to] && sum < dis2[e.to])
			{
				dis2[e.to] = sum;
				pq.push(pii(dis2[e.to], e.to));
			}
		}
	}
}

//spfa-vec
#include <queue>
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int n, m;

int dis[N];
bool vis[N];
queue<int> q;
void SPFA(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(start); vis[start] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (int i = 0; i < vec[u].size(); i++)
		{
			Edge e = vec[u][i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				if (!vis[e.to]) q.push(e.to), vis[e.to] = true;
			}
		}
	}
}

//spfa-map
#include <queue>
int map[N][N], dis[N];
int n, m;

bool vis[N];
queue<int> q;
void SPFA(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(start); vis[start] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (int i = 1; i <= n; i++)
			if (map[u][i] < INF)
			{
				int sum = dis[u] + map[u][i];
				if (sum < dis[i])
				{
					dis[i] = sum;
					if (!vis[i]) q.push(i), vis[i] = true;
				}
			}
	}
}

//bellman-ford-e
struct Edge
{
	int from, to, w;
	Edge() {};
	Edge(int from, int to, int w) : from(from), to(to), w(w) {};
} e[M];
int n, m;

int dis[N];
void bellman(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			if (dis[e[j].from] < INF)
				dis[e[j].to] = min(dis[e[j].to], dis[e[j].from] + e[j].w);
}

//floyd-map
int map[N][N];
int n, m;

void floyd()
{
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

//floyd-map-path
int map[N][N], pre[N][N];
int n, m;

void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = i;
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
				{
					int sum = map[i][k] + map[k][j];
					if (sum < map[i][j])
					{
						map[i][j] = sum;
						pre[i][j] = pre[k][j];
					}
				}
}

void printPath(int from, int to)
{
	if (from == to)
	{
		printf("%d", from);
		return;
	}
	printPath(from, pre[from][to]);
	printf("-->%d", to);
}

//kruskal-e
struct Edge
{
	int a, b, w;
} e[M];
int n, m;

int fa[N], deep[N];
void init(int n)
{
	for (int i = 1; i <= n; i++) fa[i] = i, deep[i] = 0;
}
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (deep[x] < deep[y]) fa[x] = y;
	else
	{
		fa[y] = x;
		if (deep[x] == deep[y]) deep[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}

bool cmp(Edge e1, Edge e2)
{
	return e1.w < e2.w;
}
int kruskal()
{
	sort(e, e + m, cmp);
	init(n);
	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i++)
		if (!same(e[i].a, e[i].b))
		{
			unite(e[i].a, e[i].b);
			ans += e[i].w;
			cnt++;
			if (cnt == n - 1) break;
		}
	if (cnt < n - 1) return -1;
	return ans;
}

//prim-map
int map[N][N], dis[N];
int n, m;

bool vis[N];
int prim()
{
	memset(dis, 0x7f, sizeof(dis));
	dis[1] = 0;
	memset(vis, true, sizeof(vis));
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int mini = -1;
		for (int j = 1; j <= n; j++)
			if (vis[j] && (mini == -1 || dis[j] < dis[mini]))
				mini = j;
		vis[mini] = false;
		ans += dis[mini];
		for (int j = 1; j <= n; j++)
			if (vis[j] && map[mini][j] < dis[j])
				dis[j] = map[mini][j];
	}
	return ans;
}