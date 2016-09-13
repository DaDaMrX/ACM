#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;

int n, m, d;
int p[N], dis1[N], dis2[N];

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

queue<int> q;
int vis[N];
void bfs(int start, int dis[])
{
	memset(vis, false, sizeof(vis));
	dis[start] = 0;
	while (!q.empty()) q.pop();
	q.push(start); vis[start] = true;
	while (!q.empty())
	{
		int from = q.front(); q.pop();
		for (int i = head[from]; i != -1; i = e[i].next)
		{
			int to = e[i].to;
			if (vis[to]) continue;
			dis[to] = dis[from] + 1;
			q.push(to); vis[to] = true;
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
	memset(head, -1, sizeof(head));
	num = 0;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}

	bfs(p[1], dis1);
	int s = -1;
	for (int i = 1; i <= m; i++)
		if (s == -1 || dis1[p[i]] > dis1[s]) s = p[i];

	bfs(s, dis1);
	int t = -1;
	for (int i = 1; i <= m; i++)
		if (t == -1 || dis1[p[i]] > dis1[t]) t = p[i];

	bfs(t, dis2);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dis1[i] <= d && dis2[i] <= d) ans++;
	printf("%d\n", ans);
	return 0;
}