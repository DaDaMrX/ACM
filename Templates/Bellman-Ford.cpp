/*
Bellman-Ford algorithm
SPFA while循环，不能判负环
Bellman-Ford for循环，可以判负环
*/

//SPFA + vec
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int dis[N];
bool vis[N];
int n, m;
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

//SPFA + map
int map[N][N], dis[N];
bool vis[N];
int n, m;
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

//Bellman-Ford
struct Edge
{
	int from, to, w;
	Edge() {};
	Edge(int from, int to, int w) : from(from), to(to), w(w) {};
} e[M];
int dis[N];
bool vis[N];
void bellman(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			if (dis[e[j].from] < INF)
				dis[e[j].to] = min(dis[e[j].to], dis[e[j].from] + e[j].w);
}

/*
Sample Input:
6 10
1 2 50
1 3 30
1 4 100
1 5 10
2 6 10
3 2 5
3 6 20
4 2 20
4 3 50
5 4 10

Sample Output:
1: 0
2: 35
3: 30
4: 20
5: 10
6: 45
*/