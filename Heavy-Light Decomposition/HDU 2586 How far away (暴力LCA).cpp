/*
HDU 2586 How far away (暴力LCA)
本题数据较水，用暴力LCA即可AC
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 4e4 + 10;

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

int deep[N], dis[N], fa[N];

void dfs(int u, int father, int d)
{
	fa[u] = father;
	deep[u] = deep[father] + 1;
	dis[u] = dis[father] + d;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.to != father) dfs(e.to, u, e.w);
	}
}

int lca(int u, int v)
{
	if (deep[u] < deep[v]) swap(u, v);
	while (deep[u] > deep[v]) u = fa[u];
	while (u != v) u = fa[u], v = fa[v];
	return u;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}

		deep[1] = dis[1] = 0;
		dfs(1, 1, 0);

		while (m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", dis[u] + dis[v] - 2 * dis[lca(u, v)]);
		}

	}
	return 0;
}