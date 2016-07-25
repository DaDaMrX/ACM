/*
Djikstra algorithm
未优化的dijkstra可以有判断负环，优先队列优化后的不能判断负环
*/

//1. Dijkstra + priority_queue
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];

int dis[N];
int n, m;

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
		for (auto e : vec[u])
		{
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

//建图
scanf("%d%d", &n, &m);
for (int i = 1; i <= n; i++) vec[i].clear();
for (int i = 1; i <= m; i++)
{
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w);
	vec[a].push_back(Edge(b, w));
	vec[b].push_back(Edge(a, w));
}

//静态链表
struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

memset(head, -1, sizeof(head));
num = 0;

//2. Dijkstra
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

//建图
scanf("%d%d", &n, &m);
memset(map, 0, sizeof(map));
for (int i = 1; i <= m; i++)
{
	int a, b, w;
	scanf("%d%d%d", &a, &b, &w);
	if (w < map[a][b]) map[a][b] = map[b][a] = w;
}

//3. dijkstra 次短路*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int N = 5e3 + 10;
typedef pair<int, int> pii;
struct Edge
{
	int to, w;
	Edge() {};
	Edge(int to, int w) : to(to), w(w) {};
};
vector<Edge> vec[N];
int dis1[N], dis2[N];
priority_queue<pii, vector<pii>, greater<pii> > q;
int n, m;
void dijkstra(int start)
{
	memset(dis1, 0x7f, sizeof(dis1));
	memset(dis2, 0x7f, sizeof(dis2));
	dis1[start] = 0;
	q.push(pii(dis1[start], start));
	while (!q.empty())
	{
		pii p = q.top(); q.pop();
		int u = p.second, d = p.first;
		for (int i = 0; i < vec[u].size(); i++)
		{
			Edge e = vec[u][i];
			if (d + e.w < dis1[e.to])
			{
				dis2[e.to] = dis1[e.to];
				dis1[e.to] = d + e.w;
				q.push(pii(dis2[e.to], e.to));
				q.push(pii(dis1[e.to], e.to));
			}
			else if (dis1[e.to] < d + e.w && d + e.w < dis2[e.to])
			{
				dis2[e.to] = d + e.w;
				q.push(pii(dis2[e.to], e.to));
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) vec[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		vec[a].push_back(Edge(b, w));
		vec[b].push_back(Edge(a, w));
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++)
		printf("%d: %d %d\n", i, dis1[i], dis2[i]);
	return 0;
}

/*
Sample Input
7 10
1 2 2
2 5 10
5 7 5
1 3 5
2 3 4
2 4 6
5 6 3
6 7 9
3 4 2
4 6 1

Sample Output
1: 0
2: 2
3: 5
4: 7
5: 11
6: 8
7: 16
*/