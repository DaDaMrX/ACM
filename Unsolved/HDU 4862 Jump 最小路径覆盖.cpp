#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 250;
const int M = 5e5;

int head[N], d[N], s, t, no, dis[N][N], vis[N], pre[N];
struct Edge
{
	int u, v, flow, next, cost;
	Edge() {};
	Edge(int x, int y, int z, int w, int c) : u(x), v(y), next(z), flow(w), cost(c) {};
} edge[M];
void add(int x, int y, int z, int c)
{
	edge[no] = Edge(x, y, head[x], z, c); head[x] = no++;
	edge[no] = Edge(y, x, head[y], 0, -c); head[y] = no++;
}
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
queue<int>q;
bool spfa()
{
	int x, y;
	while (!q.empty()) q.pop();
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	d[s] = 0; vis[s] = true; q.push(s);
	while (!q.empty())
	{
		x = q.front(); q.pop(); vis[x] = false;
		for (int i = head[x]; i != -1; i = edge[i].next)
		{
			if (edge[i].flow && d[y = edge[i].v] > d[x] + edge[i].cost)
			{
				d[y] = d[x] + edge[i].cost; pre[y] = i;
				if (vis[y]) continue;
				vis[y] = true; q.push(y);
			}
		}
	}
	return d[t] != d[t + 1];
}
int mcmf(int &flow)
{
	int mincost = 0, maxflow = 0, minflow, i;
	while (spfa()) {
		minflow = INF;
		for (i = pre[t]; i != -1; i = pre[edge[i].u])
			minflow = min(minflow, edge[i].flow);
		for (i = pre[t]; i != -1; i = pre[edge[i].u]) {
			edge[i].flow -= minflow;
			edge[i ^ 1].flow += minflow;
		}
		mincost += d[t] * minflow; maxflow += minflow;
	}
	flow = maxflow;
	return mincost;
}

char map[15][15];
int n, m, k;
int index(int i, int j)
{
	return (i - 1) * m + j;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &n, &m, &k);
		int total = n * m;
		for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);

		init();
		s = 0, t = 2 * total + 2;
		int tmp = 2 * total + 1;
		add(s, tmp, k, 0);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				int num = index(i, j);
				add(s, num, 1, 0);
				add(total + num, t, 1, 0);
				add(tmp, total + num, 1, 0);
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				int num = index(i, j);
				for (int jj = j + 1; jj <= m; jj++)
				{
					int cost = jj - j - 1;
					if (map[i][j] == map[j][jj]) cost -= map[i][j] - '0';
					add(num, total + index(i, jj), 1, cost);
				}
				for (int ii = i + 1; ii <= n; ii++)
				{
					int cost = ii - i - 1;
					if (map[i][j] == map[ii][j]) cost -= map[i][j] - '0';
					add(num, total + index(ii, j), 1, cost);
				}
			}

		int flow;
		int ans = mcmf(flow);
		printf("Case %d : ", cas);
		if (flow < total) printf("-1\n");
		else printf("%d\n", -ans);
	}
	return 0;
}