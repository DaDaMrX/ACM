#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;

struct Edge
{
	int to, w, next;
	Edge() {};
	Edge(int to, int w, int next): to(to), w(w), next(next) {};
} edge[2 * N];
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

int n, a[N];
int dis[N], flag[N], num[N], sum;
int path[N], t;

int bsearch(int l, int r, int key, int u)
{
	while (r - l > 1)
	{
		int m = l + r >> 1;
		if (a[u] >= dis[u] - dis[path[m]]) r = m;
		else l = m;
	}
	return path[r];
}

void dfs(int u, int f)
{
	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.to == f) dis[u] = dis[f] + e.w;
	}
	path[++t] = u;
	int v = bsearch(0, t, a[u], u);
	flag[u]++; flag[v]--;

	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.to == f) continue;
		dfs(e.to, u);
	}

	num[u] = sum;
	sum += flag[u];
}

int main()
{
	freopen("car.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w); add(v, u, w);
		}
		
		dis[1] = 0;
		memset(flag, 0, sizeof(flag));
		memset(num, 0, sizeof(num));
		sum = 0;
		t = 0;
		dfs(1, -1);

		for (int i = 1; i <= n; i++) printf("%d%c", num[i], i < n ? ' ' : '\n');
	}
	return 0;
}
